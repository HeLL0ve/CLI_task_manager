cmake_minimum_required(VERSION 4.1)
project(CLI_task_manager)

set(CMAKE_CXX_STANDARD 20)

add_executable(CLI_task_manager src/main.cpp
        src/Task.cpp
        src/TaskManager.cpp
        include/Task.h
        include/TaskManager.h)

target_include_directories(CLI_task_manager PRIVATE include)
