#include "../inc/Vector_tests.hpp"

#include <deque>

void StackConstruction()
{
    std::deque<int> mydeque(3, 100);
    container::vector<int> myvector(2, 200);

    container::stack<int> first;
    container::stack<int, std::deque<int> > second(mydeque);

    container::stack<int, container::vector<int> > third;
    container::stack<int, container::vector<int> > fourth(myvector);

    std::cout << "size of first: " << first.size() << std::endl;
    std::cout << "size of second: " << second.size() << std::endl;
    std::cout << "size of third: " << third.size() << std::endl;
    std::cout << "size of fourth: " << fourth.size() << std::endl;
}
