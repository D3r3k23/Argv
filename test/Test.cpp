#include <Argv/Argv.hpp>

#include <cstdio>
#include <format>

#define LOG(...) \
    std::puts(std::format(__VA_ARGS__).c_str())

namespace Test
{
    int Main(Argv::Argv argv)
    {
        LOG("count: {}", argv.count());

        for (auto arg : argv)
        {
            LOG("argv[{}]: {}", argv.find_index(arg), arg);
        }
        return 0;
    }
}
