@echo off
@echo building sandbox
g++ -IHazel/src -o test.exe Sandbox/src/*.cpp hazel.dll
pause
