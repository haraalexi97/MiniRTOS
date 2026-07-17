cmake_minimum_required(VERSION 3.20)

project(
    MiniRTOS
    VERSION 1.0.0
    DESCRIPTION "A Lightweight RTOS written in Modern C++"
    LANGUAGES CXX
)

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(
    MiniRTOS
    app/main.cpp
    kernel/src/Task.cpp
    scheduler/src/Scheduler.cpp
    timer/src/TickTimer.cpp
)

target_include_directories(MiniRTOS PRIVATE
    MiniRTOS
    PRIVATE
    kernel/include
    scheduler/include
    timer/include
)
