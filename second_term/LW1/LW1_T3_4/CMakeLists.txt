cmake_minimum_required(VERSION 3.24)
project(LW1_T3)

set(CMAKE_CXX_STANDARD 17)

add_executable(LW1_T3 main.cpp classes/Expression.cpp classes/Expression.h classes/Number.cpp classes/Number.h classes/BinaryOperator.cpp classes/BinaryOperator.h)
