#include "../inc/Vector_tests.hpp"

template <typename T>
class MutantStack : public container::stack<T>
{
public:
    MutantStack() {}
    MutantStack(const MutantStack<T> &src) { *this = src; }
    MutantStack<T> &operator=(const MutantStack<T> &rhs)
    {
        this->c = rhs.c;
        return *this;
    }
    ~MutantStack() {}

    void clear()
    {
        this->c.clear();
    }

    typedef typename container::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

void StackMemberFunctions()
{
    container::stack<int> s;

    for (int i = 0; i <= 10; i++)
        s.push(i);
    if (!s.empty())
        std::cout << "not empty" << std::endl;
    for (int i = 0; i <= 10; i++)
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    if (s.empty())
        std::cout << "empty" << std::endl;

    std::cout << "==== MUTANT STACK ====" << std::endl;
    MutantStack<int> mutant;
    for (int i = 0; i <= 10; i++)
        mutant.push(i);
    MutantStack<int>::iterator itr = mutant.begin();
    for (; itr != mutant.end(); itr++)
        std::cout << *itr << std::endl;
    mutant.clear();
    if (mutant.empty())
        std::cout << "Mutant empty" << std::endl;
}