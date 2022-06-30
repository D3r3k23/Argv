cmake_minimum_required(VERSION 3.10)

project(Argv)

add_library(Argv INTERFACE)
target_include_directories(Argv INTERFACE include)

set_target_properties(
  Argv PROPERIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
