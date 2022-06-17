#include "../inc/Vector_tests.hpp"

void MapSpeed() {
    container::map<int,int> m;
    clock_t start, end;
    double total;

    start = clock();
    for (int i = 0; i < 100000; i++) {
        std::cout << "inserting pair <" << i << " " << i << " >" << std::endl; 
        m.insert( container::make_pair(i,i) );
    }
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "map finished process in " << total << std::endl;
}