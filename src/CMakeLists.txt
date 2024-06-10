cmake_minimum_required (VERSION 3.24)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable (FishingGame  "main.cpp " "fishing.cpp " " ${MY_INCLUDE_DIR}/fishing.h"  )
target_include_directories(FishingGame PUBLIC ${MY_INCLUDE_DIR})
