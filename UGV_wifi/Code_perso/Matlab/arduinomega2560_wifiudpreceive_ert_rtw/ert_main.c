#include "arduinomega2560_wifiudpreceive.h"
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  arduinomega2560_wifiudpreceive_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  noInterrupts();

#endif;

  OverrunFlag--;
  rtExtModeCheckEndTrigger();
}

volatile boolean_T stopRequested = false;
int main(void)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 0.5;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(arduinomega2560_wifiudprecei_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  arduinomega2560_wifiudpreceive_initialize();
  interrupts();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(arduinomega2560_wifiudprecei_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(arduinomega2560_wifiudprecei_M->extModeInfo, 1,
      &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(arduinomega2560_wifiudprecei_M, true);
    }
  }

  rtERTExtModeStartMsg();
  noInterrupts();
  configureArduinoARMTimer();
  runModel =
    (rtmGetErrorStatus(arduinomega2560_wifiudprecei_M) == (NULL)) &&
    !rtmGetStopRequested(arduinomega2560_wifiudprecei_M);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  interrupts();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(arduinomega2560_wifiudprecei_M->extModeInfo, 1,
                       &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(arduinomega2560_wifiudprecei_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(arduinomega2560_wifiudprecei_M) ==
                       (NULL)) && !rtmGetStopRequested
                      (arduinomega2560_wifiudprecei_M));
    runModel = !(stopRequested);
    runModel = runModel && MW_Arduino_Loop();
  }

  rtExtModeShutdown(1);

  /* Disable rt_OneStep() here */

  /* Terminate model */
  arduinomega2560_wifiudpreceive_terminate();
  noInterrupts();
  return 0;
}
