cmake_minimum_required(VERSION 3.22)
project(ziya_oskernel_research C)

set(CMAKE_C_STANDARD 99)

add_executable(ziya_oskernel_research main.c tools/floppy.c tools/fileinfo.c)
