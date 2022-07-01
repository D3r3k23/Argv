add_executable(Test Test.cpp)
target_link_libraries(Test PUBLIC Argv)

target_compile_definitions(Argv INTERFACE ARGV_MAIN_NAMESPACE=Argv::Test)
