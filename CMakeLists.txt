cmake_minimum_required(VERSION 3.10)
project(MorseAlphabet VERSION 1.0)

set(CompilerFlags
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_RELEASE
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
FILE(
    GLOB MorseAlphabet_Files
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

add_executable(MorseAlphabet ${MorseAlphabet_Files})
