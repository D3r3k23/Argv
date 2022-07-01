#include <Argv/Argv.hpp>

#include <iostream>
#include <format>

namespace Test
{
    int Main(Argv::Argv argv)
    {
        std::cout << "count: " << argv.count() << std::endl;

        for (auto arg : argv)
        {
            auto index = argv.find_index(arg).value();
            // std::cout << "argv[" << index << "]: " << arg << std::endl;
            std::cout << std::format("argv[{}]: {}\n", index, arg);
        }
        return 0;
    }
}
