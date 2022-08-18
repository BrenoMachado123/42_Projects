#include "../inc/Vector_tests.hpp"

template <typename T>
static void PrintVector(T _vector)
{
    std::cout << "Size : " << _vector.size() << std::endl;
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    std::cout << "Capacity : " << _vector.capacity() << std::endl;
}

void VectorConstruction()
{
    // empty vector construction.
    container::vector<int> a;
    // reserved space vector.
    container::vector<std::string> b(5);
    // fill construction.
    container::vector<double> c(10, 42.42);
    // construction by iterating copy.
    container::vector<int> d(c.begin(), c.end());
    // construction by copy;
    container::vector<int> e(d);

    PrintVector(a);
    PrintVector(b);
    PrintVector(c);
    PrintVector(d);
    PrintVector(e);
}