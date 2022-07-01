#ifdef ARGV_ENABLE_MAIN

#ifdef ARGV_MAIN_NAMESPACE
#   define ARGV_MAIN_NAMESPACE_ENABLED 1
#else
#   define ARGV_MAIN_NAMESPACE_ENABLED 0
#   define ARGV_MAIN_NAMESPACE
#endif

#if ARGV_MAIN_NAMESPACE_ENABLED
#   define ARGV_BEGIN_MAIN_NAMESPACE namespace ARGV_MAIN_NAMESPACE {
#   define ARGV_END_MAIN_NAMESPACE }
#else
#   define ARGV_BEGIN_MAIN_NAMESPACE
#   define ARGV_END_MAIN_NAMESPACE
#endif

#include <Argv/Argv.hpp>

ARGV_BEGIN_MAIN_NAMESPACE

int Main(::Argv::Argv);

ARGV_END_MAIN_NAMESPACE

int main(int argc, char* argv[])
{
    return ARGV_MAIN_NAMESPACE::Main({argc, argv});
}

#endif // ARGV_ENABLE_MAIN
