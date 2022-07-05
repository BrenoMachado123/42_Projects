#include "../inc/Vector_tests.hpp"

/* Note:
    - erase the iterator end()/rend(), begin() in a empty map object or access a non-existent value 
    causes an UNDEFINED BEHAVIOR, so depending on the compilation and operational system it can segfault, abort the program or just use a empty pointer.
*/

template<typename T, typename InputIterator>
    static void PrintMap(T& _map, InputIterator itr) {
        std::cout << " --- Printing Map ---" << std::endl;
        std::cout << "Map size : " << _map.size() << std::endl;
        itr = _map.begin();
        for (; itr != _map.end() ; itr++) {
            std::cout << itr->first << " => " << itr->second << std::endl;
        }
    }

void mapMemberFunctions() {
    typedef typename container::pair<std::string, int> pair_type;
    typedef typename container::map<std::string, int>::iterator iterator; 
    typedef typename container::pair<iterator, bool> check_type;
    typedef typename container::map<std::string, int> map_type;

    // insert
    iterator it;
    container::map<std::string, int> m;
    //PrintMap(m,it);
    m.insert( pair_type("Root", 0) );
    check_type b = m.insert( pair_type("Root", 2) );
    check_type c = m.insert( pair_type("Xoot", 2) );
    if (!c.second)
        std::cout << "The key " << c.first->first << " with value " << c.first->second << " already belongs to BST" << std::endl;
    if (!b.second)
        std::cout << "The key " << b.first->first << " with value " << b.first->second << " already belongs to BST" << std::endl;
    PrintMap(m, it);
    m.insert(m.begin(),pair_type("Branch A", 1) ); 
    iterator get = m.insert(m.begin(),pair_type("Branch B", 2) ); // no efficiency inserting
    m.insert( pair_type("Branch C", 3) );
    m.insert( pair_type("branch D", 4) );
    m.insert( pair_type("branch E", 5) );
    m.insert( pair_type("branch F", 6) );
    std::cout << "returning iterator : "<< get->first << " => " << get->second << std::endl;
    PrintMap(m, it);

    container::map<std::string, int> m2;
    m2.insert(m.begin(), m.find("Root"));
    PrintMap(m2, it);

    //erase

    //m.erase(m.end());
    m.erase(m.find("Branch B"));
    std::cout << "TRES" << std::endl; 
    m.erase("Branch A");
    std::cout << "DUO" << std::endl; 
    m.erase(m.find("branch D"), m.end());

    PrintMap(m, it);

    // count

    std::cout << "Branch C exists ? " << (m.count("Branch C") ? "yes" : "no") << std::endl;
    std::cout << "branch D exists ? " << (m.count("branch D") ? "yes" : "no") << std::endl;
    // operator[]
    map_type m3;

    m3["Somewhere"]=1;
    m3["Over"]=2;
    m3["The"]=3;
    m3["Rainbow"]=4;
    m3["U"];

    PrintMap(m3,it);

    std::cout << "swapping content between m and m3..." << std::endl;

    // swap
    m.swap(m3);

    PrintMap(m3, it);
    PrintMap(m, it);

    //clear
    m3.clear();
    PrintMap(m3, it);


    //empty
    map_type empty_map;

    if (empty_map.empty())
        std::cout << "empty_map is empty " << std::endl;
    empty_map.insert( pair_type("I'm not empty anymore", 100) );
    if (!empty_map.empty())
        std::cout << "empty_map isn't empty " << std::endl;

    //find 
    std::cout << m.find("Rainbow")->first << std::endl;
    //std::cout << m.find("Rainboow")->first << std::endl;

    //lower_bound, upper_bound, equal_range

    map_type bound;
    bound.insert( pair_type("french", 19) );
    bound.insert( pair_type("frenchie", -22) );
    bound.insert( pair_type("fronch", 33) );
    bound.insert( pair_type("flonnch", -149) );
    bound.insert( pair_type("freench", 119) );

    PrintMap(bound, it);

    iterator t = bound.lower_bound("frenchie");
    std::cout << "lower_bound: " << t->first << " => " << t->second << std::endl;
    iterator tr = bound.upper_bound("frenchie");
    std::cout << "upper_bound: " << tr->first << " => " << tr->second << std::endl;

    container::pair<iterator, iterator> eitr = bound.equal_range("frenchie");

    std::cout << "eq_lower_bound: " << eitr.first->first << " => " << eitr.first->second << std::endl;
    std::cout << "eq_upper_bound: " << eitr.second->first << " => " << eitr.second->second << std::endl;

    //key_comp, value_comp
    
    std::cout << "--- value_compare --- " << std::endl;

    pair_type highest = *bound.rbegin();
    iterator itr = bound.begin();

    do {
        std::cout << itr->first << " => " << itr->second << std::endl;
    } while ( bound.value_comp()(*itr++, highest) );

    std::cout << "--- key_compare --- " << std::endl;

    std::string key_highest = bound.rbegin()->first;
    iterator key_itr = bound.begin();
    map_type::key_compare mycmp = bound.key_comp();

    do {
        std::cout << key_itr->first << " => " << key_itr->second << std::endl;
    } while (mycmp((*key_itr++).first, key_highest) ); 

    //get_allocator

    int psize;
    map_type alloc;
    container::pair<const std::string, int>* ptr;

    ptr = alloc.get_allocator().allocate(5);

    psize = sizeof(map_type::value_type)*5;

    std::cout << "allocated: " << psize << "bytes" << std::endl;

    alloc.get_allocator().deallocate(ptr,5);

    std::cout << "MAX SIZE ::: " << m.max_size() << std::endl;
}