cmake_minimum_required(VERSION 3.16.1)


set(BINARY_NAME 1_structured_bindings)

set(SOURCES main.cpp)

add_executable(${BINARY_NAME} ${SOURCES})
target_compile_options(${BINARY_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)

