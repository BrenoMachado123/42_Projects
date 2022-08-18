#include "../inc/Vector_tests.hpp"

template <typename T>
static void PrintVector(T _vector)
{
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

void MemberFunctions()
{
    // push_back, size and capacity
    container::vector<int> v;
    std::cout << "Initial size : " << v.size() << std::endl;
    std::cout << "Initial capacity : " << v.capacity() << std::endl;
    for (int i = 0; i <= 10; i++)
    {
        v.push_back(i);
        std::cout << "Size : " << v.size() << std::endl;
        std::cout << "Capacity : " << v.capacity() << std::endl;
    }
    PrintVector(v);
    // at
    std::cout << v.at(4) << std::endl;
    try
    {
        std::cout << v.at(-42) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    // insert
    v.insert(v.begin() + 3, 42);
    std::cout << "Capacity : " << v.capacity() << std::endl;
    v.insert(v.begin() + 5, 6, 43);
    std::cout << "Capacity : " << v.capacity() << std::endl;
    v.insert(v.end() - 2, v.begin(), v.begin() + 3);
    std::cout << "Capacity : " << v.capacity() << std::endl;
    PrintVector(v);
    std::cout << v.size() << std::endl;
    // erase
    v.erase(v.begin());
    std::cout << "Capacity : " << v.capacity() << std::endl;
    PrintVector(v);
    v.erase(v.begin() + 2, v.end() - 3);
    std::cout << "Capacity : " << v.capacity() << std::endl;
    PrintVector(v);
    // resize and reserve
    container::vector<int> resize_test(20, 1);
    std::cout << "Capacity : " << v.capacity() << std::endl;
    std::cout << resize_test.capacity() << std::endl;
    resize_test.resize(40, 2);
    std::cout << resize_test.capacity() << std::endl;
    resize_test.resize(20);
    PrintVector(resize_test);
    std::cout << resize_test.capacity() << std::endl;
    resize_test.reserve(39);
    try
    {
        resize_test.reserve(-1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << resize_test.capacity() << std::endl;
    resize_test.reserve(41);
    std::cout << resize_test.capacity() << std::endl;
    // swap
    resize_test.swap(v);
    PrintVector(v);
    std::cout << "Size : " << v.size() << std::endl;
    std::cout << "Capacity : " << v.capacity() << std::endl;
    PrintVector(resize_test);
    std::cout << "Size : " << resize_test.size() << std::endl;
    std::cout << "Capacity : " << resize_test.capacity() << std::endl;
    // pop_back, empty, front and back
    resize_test.pop_back();
    v.clear();
    PrintVector(v);
    PrintVector(resize_test);
    if (v.empty())
        std::cout << "vector V is empty now" << std::endl;
    std::cout << resize_test.front() << std::endl;
    std::cout << resize_test.back() << std::endl;
    // assign
    container::vector<int> u(10, 0);
    u.assign(7, 10);
    std::cout << "Size : " << u.size() << std::endl;
    std::cout << "Capacity : " << u.capacity() << std::endl;
    PrintVector(u);
    u.assign(resize_test.begin(), resize_test.end());
    std::cout << "Size : " << u.size() << std::endl;
    std::cout << "Capacity : " << u.capacity() << std::endl;
    PrintVector(u);
    container::vector<int> k;
    // get_allocator
    int *ptr = u.get_allocator().allocate(5);
    for (size_t i = 0; i < 5; i++)
        u.get_allocator().construct(&ptr[i], i);
    PrintVector(u);
    for (int i = 0; i < 5; i++)
        std::cout << ptr[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
        u.get_allocator().destroy(&ptr[i]);
    u.get_allocator().deallocate(ptr, 5);
    PrintVector(u);

    std::cout << u.max_size() << std::endl;
}