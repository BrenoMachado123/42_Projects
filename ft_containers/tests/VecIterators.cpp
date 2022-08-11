#include "../inc/Vector_tests.hpp"

void IteratorTest() {
    container::vector<std::string> v;
    v.push_back("test1");
    v.push_back("test2");
    v.push_back("test3");
    v.push_back("test4");

    container::vector<std::string> u;

    u.push_back("a");
    u.push_back("a");
    u.push_back("a");

    container::vector<std::string>::const_iterator itr = u.begin();
    container::vector<std::string>::const_iterator itr_end = u.end();

    u.swap(v);

    for (; itr != itr_end; itr++)
    {
        std::cout << *itr << std::endl;
    }

    //random_access_iterator
    container::vector<std::string>::iterator it = v.begin();
    container::vector<std::string>::const_iterator cit = v.begin();
    //random_access_iterator (but reversed).
    container::vector<std::string>::reverse_iterator rit = v.rbegin();
    container::vector<std::string>::const_reverse_iterator crit = v.rbegin();

    if (itr == it || itr != it) /* this condition is kinda of idiot but is just to show that both are comparable. */
    {
        std::cout << "A const iterator can be comparable with a non_const iterator" << std::endl;
    }

    while (it != v.end())
        std::cout << *it++;
    std::cout << std::endl;;
    while (cit != v.end())
        std::cout << *cit++;
    std::cout << std::endl;
    while (rit != v.rend())
        std::cout << *rit++;
    std::cout << std::endl;
    while (crit != v.rend())
        std::cout << *crit++;
    std::cout << std::endl;
}

