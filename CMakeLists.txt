cmake_minimum_required(VERSION 3.16)


project(cpp_py)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(PythonLibs REQUIRED)

add_executable(${PROJECT_NAME} cpp_py/main.cpp)

include_directories(${PROJECT_NAME} PUBLIC ${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${PYTHON_LIBRARIES})

add_executable(pyint pyint/pyinterpreter.cpp)

include_directories(pyint PUBLIC ${PYTHON_INCLUDE_DIRS})
target_link_libraries(pyint PUBLIC ${PYTHON_LIBRARIES})

add_executable(load load.cpp)

include_directories(load PUBLIC ${PYTHON_INCLUDE_DIRS})
target_link_libraries(load PUBLIC ${PYTHON_LIBRARIES})
