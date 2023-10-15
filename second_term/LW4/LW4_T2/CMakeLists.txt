cmake_minimum_required(VERSION 3.24)
project(LW4_T2)

set(CMAKE_CXX_STANDARD 20)

add_executable(LW4_T2 main.cpp)
target_link_libraries(LW4_T2 PUBLIC "/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/LW4/LW4_T2/cmake-build-debug/libString.dylib")

#add_library(String SHARED String/String.cpp Unique_ptr/Unique_ptr.cpp Unique_ptr/Unique_ptr.h String/String.h Iterators/Reverse_iterator.h Iterators/Iterator.h)
add_library(String SHARED main3.cpp)
