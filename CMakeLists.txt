cmake_minimum_required(VERSION 3.10)

project(RaylibShaders)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

find_path(RL_INCLUDE_DIR NAMES raylib.h PATHS /opt/homebrew/opt/raylib/include)
include_directories(${RL_INCLUDE_DIR})
link_directories(/opt/homebrew/opt/raylib/lib)


add_executable(main main.cpp)

target_link_libraries(main raylib)

if (APPLE)
    target_link_libraries(main
    "-framework IOKit"
    "-framework Cocoa"
    "-framework OpenGL"
)
endif()
