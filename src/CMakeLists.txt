cmake_minimum_required(VERSION 3.15)
project(POA_L1)

set(CMAKE_CXX_STANDARD 14)

add_executable(POA_L1 main.cpp matrix.cpp Operation.cpp Operation.h Add.cpp Add.h Sub.cpp Sub.h Multiply.cpp Multiply.h)