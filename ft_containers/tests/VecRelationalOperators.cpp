#include "../inc/Vector_tests.hpp"

template<typename T>
    static void PrintVector(T _vector) {
        for(size_t i = 0; i < _vector.size() ;i++)
            std::cout << _vector[i] << " ";
        std::cout << std::endl;
    }

void RelationalOperators() {
    container::vector<int> v1;
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(9);
    container::vector<int> v2;
    v2.push_back(17);
    v2.push_back(512);
    v2.push_back(1);
    v2.push_back(92);
    v2.push_back(13);

    if (v1 == v2) std::cout << "v1 == v2" << std::endl;
    if (v1 != v2) std::cout << "v1 != v2" << std::endl;
    if (v1 < v2) std::cout << "v1 < v2" << std::endl;
    if (v1 > v2) std::cout << "v1 > v2" << std::endl;
    if (v1 >= v2) std::cout << "v1 >= v2" << std::endl;
    if (v1 <= v2) std::cout << "v1 <= v2" << std::endl;
    PrintVector(v1);
    PrintVector(v2);
    container::swap(v1,v2);
    PrintVector(v1);
    PrintVector(v2);

}