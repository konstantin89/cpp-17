cmake_minimum_required(VERSION 3.16.1)

project("C++17 examples")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(1_structured_bindings)
add_subdirectory(3.4_inline_and_thread_local)

