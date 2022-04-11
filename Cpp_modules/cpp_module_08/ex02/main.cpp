#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5); // adding values to stack;
	mstack.push(17);

	std::cout << "Initial Value on the top: " << mstack.top() << std::endl;

	mstack.pop(); // remove the value of the top;

	std::cout << "Size of the stack when top was removed: " << mstack.size() << std::endl;

	std::cout << "This is the new top: " << mstack.top() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Adding the values: 3, 5, 737, 0" << std::endl; 

	MutantStack<int>::iter it = mstack.begin(); // getting the iterator of the first;
	MutantStack<int>::iter ite = mstack.end(); // getting the iterator of the last;

	++it;
	--it;
	while (it != ite) {
    	std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack); // stack copied the mstack
	return 0;
}
