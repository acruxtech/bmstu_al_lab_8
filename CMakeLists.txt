cmake_minimum_required(VERSION 3.10)

project(bmstu_al_lab_8)

file(GLOB_RECURSE SRC "source/*.cpp")
include_directories(include)

add_library(task2 source/task2.cpp)
add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME})  
