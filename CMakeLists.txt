cmake_minimum_required(VERSION 3.10)

project(c_py_ai LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

find_package(PythonLibs REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(${PROJECT_NAME} PUBLIC ${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${PYTHON_LIBRARIES})

add_executable(pyint pyinterpreter.cpp)

include_directories(pyint PUBLIC ${PYTHON_INCLUDE_DIRS})
target_link_libraries(pyint PUBLIC ${PYTHON_LIBRARIES})
