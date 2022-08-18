#include "../inc/Vector_tests.hpp"
#include <cstdlib>

void MapSpeed()
{
    container::map<int, int> m;
    clock_t start, end;
    double total;

    start = clock();
    for (int i = 0; i < 1000000; i++)
    {
        int element = rand();
        if (i % 1000 == 0)
            std::cout << "#";
        m.insert(container::make_pair(element, i));
    }
    std::cout << std::endl;
    std::cout << "deleting all..." << std::endl;
    size_t size = m.size();
    std::cout << size << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        container::map<int, int>::iterator itr = m.begin();
        if (i % 1000 == 0)
            std::cout << "#";
        m.erase(itr->first);
    }
    std::cout << std::endl;
    if (m.empty())
        std::cout << "all deleted!" << std::endl;
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "map finished process in " << total << std::endl;
}