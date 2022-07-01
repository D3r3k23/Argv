#ifndef ARGV_HPP
#define ARGV_HPP

#include <string_view>
#include <vector>
#include <optional>
#include <algorithm>
#include <iterator>

namespace Argv
{
    class Argv
    {
        using Container = std::vector<std::string_view>;
        using Iterator = Container::const_iterator;
        using Size = Container::size_type;

    public:
        Argv(int argc, char* argv[])
          : m_argv(argc)
        {
            for (int i = 0; i < count(); ++i)
                m_argv[i] = argv[i];
        }

        std::string_view operator[](int i) const
        {
            return m_argv[i];
        }

        std::optional<std::string_view> get(int i) const
        {
            if (i < count())
                return m_argv[i];
            else
                return {};
        }

        Size count(void) const
        {
            return size();
        }

        Size size(void) const
        {
            return m_argv.size();
        }

        std::optional<Size> find_index(std::string_view arg) const
        {
            if (auto it = find(arg); it != end())
                return std::distance(begin(), it);
            else
                return {};
        }

        bool contains(std::string_view arg) const
        {
            return find(arg) != end();
        }

        Iterator find(std::string_view arg) const
        {
            return std::ranges::find(m_argv, arg);
        }

        Iterator begin(void) const
        {
            return m_argv.cbegin();
        }

        Iterator end(void) const
        {
            return m_argv.cend();
        }

    private:
        Container m_argv;
    };
}

#endif // ARGV_HPP
