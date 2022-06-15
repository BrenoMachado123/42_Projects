#include "../inc/Vector_tests.hpp"

//Yes. Elden Ring reference. My project, my tests. Deal with it.
void IteratorTest() {
    container::vector<std::string> v;
    v.push_back("Welcome");
    v.push_back(", honored guest.");
    v.push_back(" To the birthplace");
    v.push_back(" of our dinasty!");
    //random_access_iterator
    container::vector<std::string>::iterator it = v.begin();
    container::vector<std::string>::const_iterator cit = v.begin();
    //random_access_iterator (but reversed).
    container::vector<std::string>::reverse_iterator rit = v.rbegin();
    container::vector<std::string>::const_reverse_iterator crit = v.rbegin();

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

