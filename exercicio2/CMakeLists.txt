cmake_minimum_required(VERSION 3.25)
project(exercicio2)

set(CMAKE_CXX_STANDARD 14)

add_executable(exercicio2
        main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(${CMAKE_PROJECT_NAME} glut GLU GL m )