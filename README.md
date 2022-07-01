# Argv

[![Test](https://github.com/D3r3k23/Argv/actions/workflows/test.yaml/badge.svg)](https://github.com/D3r3k23/Argv/actions/workflows/test.yaml)

Modern C++ (C++20) wrapper for the "classic" (i.e. outdated) command line arguments (int argc, char* argv[])

**Want a modern C++ main function? Define `ARGV_ENABLE_MAIN` or `ARGV_MAIN_NAMESPACE` in CMake, then use the Argv Main signature:**

`int Main(Argv::Argv)`

### CMake

#### Link to project

```cmake
add_subdirectory(Argv)
target_compile_definitions(Argv INTERFACE ARGV_MAIN_NAMESPACE=<YOUR_NAMESPACE>)
# or
target_compile_definitions(Argv INTERFACE ARGV_ENABLE_MAIN)
```

#### Build test program
```
$ mkdir build
$ cmake . -B build
$ cmake --build build
```
##### Run
```
$ build/test/Test arg1 opt2 3 4
```

### Argv Main

```cpp
int <ARGV_MAIN_NAMESPACE>::Main(Argv::Argv argv)
{
    auto arg0 = argv[0]; // Program
    for (auto arg : argv)
    {
        // use arg...
    }
    return 0;
}
```

* You can still use the old main with Argv:

```cpp
int main(int c_argc, char* c_argv[])
{
    Argv::Argv argv(c_argc, c_argv);

    // use argv...

    return 0;
}
```

| `int ::main(int argc, char* argv[])` | `int Main(Argv::Argv argv)`    |
| :----------------------------------: | :----------------------------: |
| C-syle                               | **Modern C++**                 |
| 2 parameters                         | ***Single* parameter**         |
| Pointer to `const char*`             | **Container of `string_view`** |
| Global scope                         | **Namespaced**                 |

* Note: the args are stored with a string_view so Argv does not own them; this is fine since `argv` in `main` lasts the lifetime of the program
