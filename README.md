# Argv
C++ 20 wrapper for C-style command line arguments (int argc, char* argv[])

Want a modern C++ style main function? Define ARGV_ENABLE_MAIN or ARGV_MAIN_NAMESPACE in CMake, then using the Argv Main signature:
```
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
