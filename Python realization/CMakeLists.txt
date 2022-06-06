cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(A1_py_sdk)

# Include dir
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O3 -march=native -Wall")
include_directories(/usr/local/include)

include_directories(
    include
)

link_directories(
    lib
)

link_directories(lib)
set(EXTRA_LIBS libunitreeMotorSDK_Linux64.so)

add_subdirectory(pybind11)
pybind11_add_module(A1_py_sdk A1_py.cpp)
target_link_libraries(A1_py_sdk ${EXTRA_LIBS})