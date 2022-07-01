add_executable(Test Test.cpp)
target_link_libraries(Test PUBLIC Argv)

target_compile_definitions(Test PUBLIC ARGV_MAIN_NAMESPACE=Argv::Test)
