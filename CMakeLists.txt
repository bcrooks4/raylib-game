cmake_minimum_required(VERSION 3.17)
project(Raylib_Game C)

set(CMAKE_C_STANDARD 99)

INCLUDE_DIRECTORIES(
        C:/dev/vcpkg/installed/x64-windows/include
)
LINK_DIRECTORIES(
        C:/dev/vcpkg/installed/x64-windows/lib
)

add_executable(Raylib_Game main.c)

TARGET_LINK_LIBRARIES(
        Raylib_Game
        raylib
)