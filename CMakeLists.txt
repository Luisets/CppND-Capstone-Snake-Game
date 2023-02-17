cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
add_definitions(-std=c++17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

include_directories(include)

file(GLOB headers include/*.h)
file(GLOB sources src/*.cpp)

set(PROJECT_SOURCES
        ${headers}
        ${sources}
)

add_executable(SnakeGame ${PROJECT_SOURCES})
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(SnakeGame ${SDL2_LIBRARIES})
