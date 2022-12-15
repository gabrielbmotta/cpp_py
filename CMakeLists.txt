project(cpp_py)

find_package(PythonLibs)

add_executable(${PROJECT_NAME} main.cpp)

include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARIES})

