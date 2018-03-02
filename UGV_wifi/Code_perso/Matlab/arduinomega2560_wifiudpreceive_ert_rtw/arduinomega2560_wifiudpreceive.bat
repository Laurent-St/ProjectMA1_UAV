@echo off

cd .

if "%1"=="" ("D:\MATLAB~2\bin\win64\gmake"  -f arduinomega2560_wifiudpreceive.mk all) else ("D:\MATLAB~2\bin\win64\gmake"  -f arduinomega2560_wifiudpreceive.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
