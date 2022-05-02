cmake_minimum_required(VERSION 3.17)
project(miniRt)

set(CMAKE_CXX_STANDARD 11)

file(GLOB includes "includes/*.h")
file(GLOB srcs "srcs/*.c" "srcs/*/*.c")
file(GLOB libft "libft/*.c" "libft/*/*.c")
add_executable(miniRT ${includes} ${srcs} ${libft})