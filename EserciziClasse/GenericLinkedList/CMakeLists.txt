cmake_minimum_required(VERSION 3.17)
project(GenericLinkedList)

set(CMAKE_CXX_STANDARD 11)

add_executable(GenericLinkedList main.cpp LinkedList.h Node.h LinkedList.cpp)