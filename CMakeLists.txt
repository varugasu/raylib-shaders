cmake_minimum_required(VERSION 3.10)

project(RaylibShaders)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

find_path(RL_INCLUDE_DIR NAMES raylib.h PATHS /opt/homebrew/opt/raylib/include)
include_directories(${RL_INCLUDE_DIR})
link_directories(/opt/homebrew/opt/raylib/lib)

# Function to add an executable with Raylib dependencies
function(add_raylib_executable TARGET_NAME SOURCE_FILE)
    add_executable(${TARGET_NAME} ${SOURCE_FILE})
    target_link_libraries(${TARGET_NAME} raylib)
    if (APPLE)
        target_link_libraries(${TARGET_NAME}
            "-framework IOKit"
            "-framework Cocoa"
            "-framework OpenGL"
        )
    endif()
    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET_NAME}/bin)
endfunction()

# Add main executable
add_raylib_executable(u_time ./u_time/u_time.cpp)

# Add fragcoord executable
add_raylib_executable(fragcoord ./fragcoord/fragcoord.cpp)
