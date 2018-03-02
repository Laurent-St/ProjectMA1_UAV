#include "arduinodue_wifiudpreceive.h"
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

  arduinodue_wifiudpreceive_step();

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
  rtmSetErrorStatus(arduinodue_wifiudpreceive_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  arduinodue_wifiudpreceive_initialize();
  interrupts();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(arduinodue_wifiudpreceive_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(arduinodue_wifiudpreceive_M->extModeInfo, 1,
      &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(arduinodue_wifiudpreceive_M, true);
    }
  }

  rtERTExtModeStartMsg();
  noInterrupts();
  configureArduinoARMTimer();
  runModel =
    (rtmGetErrorStatus(arduinodue_wifiudpreceive_M) == (NULL)) &&
    !rtmGetStopRequested(arduinodue_wifiudpreceive_M);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  interrupts();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(arduinodue_wifiudpreceive_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(arduinodue_wifiudpreceive_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(arduinodue_wifiudpreceive_M) == (NULL))
                      && !rtmGetStopRequested(arduinodue_wifiudpreceive_M));
    runModel = !(stopRequested);
    runModel = runModel && MW_Arduino_Loop();
  }

  rtExtModeShutdown(1);

  /* Disable rt_OneStep() here */

  /* Terminate model */
  arduinodue_wifiudpreceive_terminate();
  noInterrupts();
  return 0;
}
