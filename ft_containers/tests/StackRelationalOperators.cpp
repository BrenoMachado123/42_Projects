#include "../inc/Vector_tests.hpp"

void StackRelationalOperators()
{
    container::stack<int> v1;
    v1.push(3);
    v1.push(5);
    v1.push(6);
    v1.push(7);
    v1.push(9);
    container::stack<int> v2;
    v2.push(17);
    v2.push(512);
    v2.push(1);
    v2.push(92);
    v2.push(13);

    if (v1 == v2)
        std::cout << "v1 == v2" << std::endl;
    if (v1 != v2)
        std::cout << "v1 != v2" << std::endl;
    if (v1 < v2)
        std::cout << "v1 < v2" << std::endl;
    if (v1 > v2)
        std::cout << "v1 > v2" << std::endl;
    if (v1 >= v2)
        std::cout << "v1 >= v2" << std::endl;
    if (v1 <= v2)
        std::cout << "v1 <= v2" << std::endl;
}
