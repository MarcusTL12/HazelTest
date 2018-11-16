@echo off
@echo precompiling requested files
g++ -fPIC -O3 -I../vendor/spdlog/include -D HZ_PLATFORM_WINDOWS -c src/*.cpp
pause
