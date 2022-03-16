cmake_minimum_required(VERSION 3.15)
project(POA_L1)

set(CMAKE_CXX_STANDARD 14)

add_executable(POA_L1 main.cpp Operation.h Add.cpp Add.h Sub.cpp Sub.h Multiply.cpp Multiply.h Matrix.cpp Matrix.h Random.cpp Random.h)