@echo off
@echo building sandbox
g++ -D HZ_PLATFORM_WINDOWS -IHazel/vendor/spdlog/include -IHazel/src -o test.exe Sandbox/src/*.cpp hazel.dll
pause
