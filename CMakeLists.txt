cmake_minimum_required(VERSION 3.21)

option(ARGV_ENABLE_MAIN "Enable Argv Main" OFF)

project(Argv)

add_library(Argv INTERFACE src/main.cpp)
target_include_directories(Argv INTERFACE include)

set_target_properties(
  Argv PROPERIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

if(${ARGV_ENABLE_MAIN})
    target_compile_definitions(Argv
      INTERFACE
        ARGV_ENABLE_MAIN
    )
endif()

if (PROJECT_IS_TOP_LEVEL)
    add_subdirectory(test)
endif()
