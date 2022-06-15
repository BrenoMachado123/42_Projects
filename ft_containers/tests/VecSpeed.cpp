#include "../inc/Vector_tests.hpp"
#include <time.h>

void VSpeedTest() {
    container::vector<int> v;
    clock_t start, end;
    double total;

    start = clock();
    for (int i = 0; i < 1000000000; i++) {
        v.push_back(0);
    }
    end = clock();
    total = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "vector finished process in " << total << std::endl;
}