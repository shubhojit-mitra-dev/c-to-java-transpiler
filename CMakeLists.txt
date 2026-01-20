cmake_minimum_required(VERSION 3.16)
project(c_to_java_transpiler)

set(CMAKE_CXX_STANDARD 17)

add_library(lexer
    lexer/Lexer.cpp
)

target_include_directories(lexer PUBLIC lexer)

add_executable(lexer_test
    tests/lexer/lexer_test.cpp
)

target_link_libraries(lexer_test lexer)
