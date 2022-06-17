#include "../inc/Vector_tests.hpp"
#include <time.h>

void VSpeedTest() {
    container::vector<int> v;
    clock_t start, end;
    double total;

    start = clock();
    for (int i = 0; i < 100000; i++) {
         std::cout << "inserting element: " << i << std::endl; 
        v.push_back(i);
    }
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "vector finished process in " << total << std::endl;
}