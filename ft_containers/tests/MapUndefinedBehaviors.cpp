#include "../inc/Vector_tests.hpp"

template<typename T, typename InputIterator>
    static void PrintMap(T& _map, InputIterator itr) {
        std::cout << " --- Printing Map ---" << std::endl;
        std::cout << "Map size : " << _map.size() << std::endl;
        itr = _map.begin();
        for (; itr != _map.end() ; itr++) {
            std::cout << itr->first << " => " << itr->second << std::endl;
        }
    }

void MapUndefinedBehaviors() {
    /*typedef typename container::map<std::string, int>::iterator iterator; 
    typedef typename container::pair<iterator, bool> check_type;*/
    typedef typename container::map<std::string, int> str_map_type;
    typedef typename container::map<char, int> char_map_type;
    typedef typename container::map<int, int> int_map_type;

    str_map_type strMap;
    char_map_type charMap;
    int_map_type intMap;

    str_map_type::iterator str_itr;
    char_map_type::iterator char_itr;
    int_map_type::iterator int_itr;

    PrintMap(strMap, str_itr);
    PrintMap(charMap, char_itr);
    PrintMap(intMap, int_itr);

    std::cout << intMap.find('a')->first << std::endl;
}