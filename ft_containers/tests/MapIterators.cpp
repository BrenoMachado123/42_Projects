#include "../inc/Vector_tests.hpp"

void MapIterators()
{
    typedef container::map<std::string, int> map_type;
    typedef container::pair<std::string, int> pair_type;
    map_type::iterator itr;
    map_type::const_iterator const_itr;
    map_type::reverse_iterator rev_itr;
    map_type::const_reverse_iterator cont_rev_itr;

    map_type m;

    m.insert(pair_type("test1", 1));
    m.insert(pair_type("test2", 2));
    m.insert(pair_type("test3", 3));
    m.insert(pair_type("test4", 4));
    m.insert(pair_type("test5", 5));

    map_type n;

    n.insert(pair_type("hello", 0));
    n.insert(pair_type("world", 1));
    n.insert(pair_type("!!!", 1));

    map_type::const_iterator n_itr = n.begin();
    // map_type::iterator n_itr_end = n.end(); // for some reason, use this end() at the loop in STD::map causes undefined behavior.

    n.swap(m);

    for (; n_itr != m.end(); n_itr++)
    {
        std::cout << n_itr->first << std::endl;
    }

    if (itr == n_itr || n_itr != itr) /* this condition is kinda of idiot but is just to show that both are comparable. */
    {
        std::cout << "A const iterator can be comparable with a non_const iterator" << std::endl;
    }

    itr = m.begin();
    const_itr = m.begin();
    rev_itr = m.rbegin();
    cont_rev_itr = m.rbegin();

    for (; itr != m.end(); itr++)
        std::cout << itr->first << " => " << itr->second << std::endl;
    for (; const_itr != m.end(); const_itr++)
        std::cout << const_itr->first << " => " << const_itr->second << std::endl;
    for (; rev_itr != m.rend(); rev_itr++)
        std::cout << rev_itr->first << " => " << rev_itr->second << std::endl;
    for (; cont_rev_itr != m.rend(); cont_rev_itr++)
        std::cout << cont_rev_itr->first << " => " << cont_rev_itr->second << std::endl;
}
