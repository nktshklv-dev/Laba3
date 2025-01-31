cmake_minimum_required(VERSION 3.28)
project(Laba3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Laba3 main.cpp
        Backpack.h
        Item.h
        Item.cpp
        Backpack.cpp
        ISequence.h
        DynamicArray.h
        DynamicArray.tpp
        HashTable.h
        HashTable.tpp
        State.h
        State.cpp)
