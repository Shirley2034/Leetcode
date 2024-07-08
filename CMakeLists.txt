cmake_minimum_required(VERSION 3.28)
project(lc)

set(CMAKE_CXX_STANDARD 17)

add_executable(lc main.cpp
        Easy/LinkedList.cpp
        Easy/LinkedList.h
        Easy/Array.cpp
        Easy/Array.h
        Easy/MATH.cpp
        Easy/MATH.h
        Easy/TREE.cpp
        Easy/TREE.h
        Easy/STRING.cpp
)
