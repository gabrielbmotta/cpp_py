cmake_minimum_required(VERSION 3.16)

project(cpp_py)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PythonLibs)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARIES})

