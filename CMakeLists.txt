cmake_minimum_required(VERSION 3.17)
project(miniRt)

set(CMAKE_CXX_STANDARD 11)

file(GLOB includes "includes/*.h")
file(GLOB srcs "srcs/*.c")
add_executable(miniRt ${includes} ${srcs})