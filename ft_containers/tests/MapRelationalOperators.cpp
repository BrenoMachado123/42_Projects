#include "../inc/Vector_tests.hpp"

template <typename T, typename InputIterator>
static void PrintMap(T &_map, InputIterator itr)
{
    std::cout << " --- Printing Map ---" << std::endl;
    std::cout << "Map size : " << _map.size() << std::endl;
    itr = _map.begin();
    for (; itr != _map.end(); itr++)
    {
        std::cout << itr->first << " => " << itr->second << std::endl;
    }
}

void MapRelationalOperators()
{
    typedef container::map<char, int> char_map_type;
    char_map_type::iterator char_itr;

    char_map_type foo;
    char_map_type bar;

    foo['a'] = 13;
    foo['b'] = 12;
    bar['a'] = 12;
    bar['z'] = 13;

    if (foo == bar)
        std::cout << "foo == bar" << std::endl;
    if (foo != bar)
        std::cout << "foo != bar" << std::endl;
    if (foo < bar)
        std::cout << "foo < bar" << std::endl;
    if (foo > bar)
        std::cout << "foo > bar" << std::endl;
    if (foo <= bar)
        std::cout << "foo <= bar" << std::endl;
    if (foo >= bar)
        std::cout << "foo >= bar" << std::endl;

    std::cout << "=== foo ===" << std::endl;
    PrintMap(foo, char_itr);
    std::cout << "=== bar ===" << std::endl;
    PrintMap(bar, char_itr);

    container::swap(foo, bar);
    std::cout << "=== foo ===" << std::endl;
    PrintMap(foo, char_itr);
    std::cout << "=== bar ===" << std::endl;
    PrintMap(bar, char_itr);
}