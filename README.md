# Argv
C++ 20 wrapper for C-style command line arguments (int argc, char* argv[])

Want a modern C++ style main function? Define `ARGV_ENABLE_MAIN` or `ARGV_MAIN_NAMESPACE` in CMake, then use the Argv Main signature: `int Main(Argv::Argv)`

```cmake
add_subdirectory(Argv)
target_compile_definitions(Argv INTERFACE ARGV_MAIN_NAMESPACE=<YOUR_NAMESPACE>)
# or
target_compile_definitions(Argv INTERFACE ARGV_ENABLE_MAIN)
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
int main(int c_argc, char* c_argv[])
{
    Argv::Argv argv(c_argc, c_argv);

    // use argv...

    return 0;
}
```

| `int ::main(int argc, char* argv[])` | `int Main(Argv::Argv argv)` |
| :----------------------------------: | :-------------------------: |
| C-syle                               | Modern C++                  |
| 2 parameters                         | 1 parameter                 |
| Pointer to `const char*`             | Container of `string_view`  |
| Global scope                         | Namespaced                  |
