cmake_minimum_required(VERSION 3.19)

project(MyApp Main.cpp)
add_executable(MyApp)

set(ARGV_ENABLE_MAIN ON)
add_subdirectory(Argv)

target_link_libraries(MyApp PUBLIC Argv)
target_compile_definitions(MyApp PRIVATE ARGV_MAIN_NAMESPACE=MyApp)
