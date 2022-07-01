#if defined(ARGV_MAIN_NAMESPACE)
#   define ARGV_ENABLE_MAIN 1
#elif defined(ARGV_ENABLE_MAIN)
#   define ARGV_ENABLE_MAIN 1
#   define ARGV_MAIN_NAMESPACE
#else
#   define ARGV_ENABLE_MAIN 0
#endif

#if ARGV_ENABLE_MAIN

    #include <Argv/Argv.hpp>

    namespace ARGV_MAIN_NAMESPACE
    {
        int Main(Argv::Argv);
    }

    int main(int argc, char* argv[])
    {
        return ARGV_MAIN_NAMESPACE::Main(Argv::Argv{argc, argv});
    }

#endif
