cmake_minimum_required(VERSION 3.19)

project(Argv)

option(ARGV_ENABLE_MAIN "Enable Argv Main" OFF)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    set(ARGV_TOP_LEVEL TRUE)
else()
    set(ARGV_TOP_LEVEL FALSE)
endif()

add_library(Argv INTERFACE)

target_include_directories(Argv INTERFACE include)
target_sources(Argv INTERFACE src/main.cpp)

target_compile_features(Argv INTERFACE cxx_std_20)

if(${ARGV_ENABLE_MAIN})
    target_compile_definitions(Argv
      INTERFACE
        ARGV_ENABLE_MAIN
    )
endif()

if (${ARGV_TOP_LEVEL})
    message("Building tests")
    add_subdirectory(test)
endif()
