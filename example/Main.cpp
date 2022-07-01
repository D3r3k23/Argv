#include "MyClass.hpp"

#include <Argv/Argv.hpp>

namespace MyApp
{
    int Main(Argv::Argv argv)
    {
        MyClass x;
        x.f();

        return 0;
    }
}
