@echo off
@echo building hazel engine
g++ -fPIC -c Hazel/src/Hazel/*.cpp
g++ -shared -o hazel.dll *.o
del *.o
pause
