#include <Argv/Argv.hpp>

#include <cstdio>
#include <format>

#define LOG(...) \
    std::puts(std::format(__VA_ARGS__))

namespace Test
{
    int Main(Argv::Argv argv)
    {
        for (auto arg : argv)
        {
            LOG(arg);
        }
        return 0;
    }
}
