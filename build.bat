@ECHO OFF

IF EXIST build RD /S /Q build
mkdir build && cd build
CALL cmake ..
CALL cmake --build . --config release
cd release
start /wait /b cmd.exe /k