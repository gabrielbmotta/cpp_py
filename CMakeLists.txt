cmake_minimum_required(VERSION 3.16)


project(cpp_py)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(Python REQUIRED Interpreter Development)

message("Include dirs: ${Python_INCLUDE_DIRS}")
message("Libs: ${Python_LIBRARIES}")
message("Link options: ${Python_LINK_OPTIONS}")
message("Executable: ${Python_EXECUTABLE}")


add_executable(${PROJECT_NAME} cpp_py/main.cpp)

include_directories(${PROJECT_NAME} PUBLIC ${Python_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${Python_LIBRARIES})

add_executable(pyint pyint/pyinterpreter.cpp)

include_directories(pyint PUBLIC ${Python_INCLUDE_DIRS})
target_link_libraries(pyint PUBLIC ${Python_LIBRARIES})

add_executable(load load/load.cpp)

include_directories(load PUBLIC ${Python_INCLUDE_DIRS})
target_link_libraries(load PUBLIC ${Python_LIBRARIES})

