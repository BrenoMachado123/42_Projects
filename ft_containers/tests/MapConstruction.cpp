#include "../inc/Vector_tests.hpp"

template <typename T, typename InputIterator>
static void PrintMap(T &_map, InputIterator itr)
{
    std::cout << "Map size : " << _map.size() << std::endl;
    itr = _map.begin();
    for (; itr != _map.end(); itr++)
    {
        std::cout << itr->first << " => " << itr->second << std::endl;
    }
}

void MapConstruction()
{
    container::map<int, int> a;
    container::map<int, int>::iterator it;
    std::cout << a.max_size() << std::endl;
    PrintMap(a, it);

    a.insert(container::pair<int, int>(1, 1));
    a.insert(container::pair<int, int>(2, 2));
    a.insert(container::pair<int, int>(3, 3));
    a.insert(container::pair<int, int>(4, 4));
    a.insert(container::pair<int, int>(5, 5));

    container::map<int, int> copy_range(a.begin(), a.end());
    container::map<int, int> copy(copy_range);

    PrintMap(a, it);
    PrintMap(copy_range, it);
    PrintMap(copy, it);
}