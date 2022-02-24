@ECHO OFF

IF EXIST build RD /S /Q build
IF EXIST CMakeFiles RD /S /Q CMakeFiles
IF EXIST CMakeCache.txt del CMakeCache.txt
mkdir build && cd build
CALL cmake ..
CALL cmake --build . --config release
cd release
start /wait /b cmd.exe /k