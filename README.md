# Argv
C++ 20 wrapper for C-style command line arguments (int argc, char* argv[])

Want a modern C++ style main function? Define ARGV_ENABLE_MAIN or ARGV_MAIN_NAMESPACE in CMake, then using the Argv Main signature:

```cmake
add_subdirectory(Argv)
target_compile_definitions(Argv INTERFACE ARGV_MAIN_NAMESPACE=<YOUR_NAMESPACE>)
```

```cpp
int <ARGV_MAIN_NAMESPACE>::Main(Argv::Argv argv)
{
    auto arg0 = argv[0];
    for (auto arg : argv)
    {
        // use arg...
    }
    return 0;
}
```

Or still use the regular main:
```cpp
int main(int old_argc, char* old_argv[])
{
    Argv::Argv argv(old_argc, old_argv);
    
    // use argv...
    
    return 0;
}
```
