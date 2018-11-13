@echo off
@echo building hazel engine
g++ -fPIC -IHazel/vendor/spdlog/include -D HZ_PLATFORM_WINDOWS -c Hazel/src/Hazel/*.cpp
g++ -shared -o hazel.dll *.o
del *.o
pause
