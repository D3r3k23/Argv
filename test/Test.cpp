#include <Argv/Argv.hpp>

#include <iostream>
#include <format>

namespace Argv::Test
{
    int Main(Argv argv)
    {
        std::cout << std::format("count: {}", argv.count()) << '\n';
        for (auto arg : argv)
        {
            auto index = argv.find_index(arg).value();
            std::cout << std::format("argv[{}]: {}", index, arg) << '\n';
        }
        return 0;
    }
}
