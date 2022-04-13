#include "vector.hpp"
#include <iostream>
#include <vector>

template<typename T>
void	printVector(const ft::vector<T>& vector) {
	std::cout << "~~~~~~~ PRINT ~~~~~~" << std::endl; 
	std::cout << vector.size() << std::endl;
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << std::endl;
	std::cout << vector.capacity() << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl; 
}

/*static void _testReserve() {
	ft::vector<int>::size_type sz;

  	ft::vector<int> foo;
  	sz = foo.capacity();
  	std::cout << "making foo grow:\n";
  	for (int i=0; i<100; ++i) {
  	  foo.push_back(i);
  	  if (sz!=foo.capacity()) {
		  sz = foo.capacity();
		  std::cout << "capacity changed: " << sz << '\n';
	  }
	}
	ft::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
    }
  }
}

static void	testResize() {
	ft::vector<int> myvector;
	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

  	myvector.resize(5);
  	myvector.resize(8,100);
  	myvector.resize(12);

  	std::cout << "myvector contains:";
  	for (int i=0;i<myvector.size();i++)
    	std::cout << ' ' << myvector[i];
  	std::cout << '\n';
	std::cout << "capacity : " << myvector.capacity() << std::endl;
	std::cout << "size : " << myvector.size() << std::endl;
}

static void testGetAllocator() {
	ft::vector<int> myvector;
  	int * p;
  	unsigned int i;

  	// allocate an array with space for 5 elements using vector's allocator:
  	p = myvector.get_allocator().allocate(5);

  	// construct values in-place on the array:
  	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  	std::cout << "The allocated array contains:";
  	for (i=0; i<5; i++) std::cout << ' ' << p[i];
  	std::cout << '\n';

  	// destroy and deallocate:
  	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  	myvector.get_allocator().deallocate(p,5);
}

static void testAt() {

	ft::vector<int> myvector (10);   // 10 zero-initialized ints

  	// assign some values:
  	for (unsigned i=0; i<myvector.size(); i++)
    	myvector.at(i)=i;

  	std::cout << "myvector contains:";
  	for (unsigned i=0; i<myvector.size(); i++)
    	std::cout << ' ' << myvector.at(i);
  	std::cout << '\n';
}*/

static void testIterator() {
	ft::vector<int> a;
	std::vector<int> dummy;
	for (size_t i = 0; i < 10; i++) {
		a.push_back(i);
		dummy.push_back(i);
	}

	//some bugs to fix in reverse iterator;
	std::vector<int>::reverse_iterator r_start = dummy.rbegin();
	std::vector<int>::reverse_iterator r_end = dummy.rend();
	ft::vector<int>::reverse_iterator start = a.rbegin();
	ft::vector<int>::reverse_iterator end = a.rend();


	while (end != start) {
		std::cout << *end << std::endl;
		end--;
	}
	std::cout << std::endl;
	while (r_end != r_start) {
		std::cout << *r_end << std::endl;
		r_end--;
	}

}

int main() {
	testIterator();
	//_testReserve();
	//testResize();
	//testGetAllocator();
	/*try {
		std::vector<std::string> a;
		std::cout << a.capacity() << std::endl;
		std::cout << a.size() << std::endl;
  		ft::vector<std::string> b;
		std::cout << b.capacity() << std::endl;
		std::cout << b.size() << std::endl;
		if (b.empty())
			std::cout << "empty for now" << std::endl;
		for (int i = 0; i < 3; i++) {
			b.push_back("Hello");
			b.push_back("World");
			b.push_back("!!!!");
		}
		b.push_back("-----");
		b.pop_back();
		//b.clear();
		printVector(b);
		b.push_back("--1--");
		b.push_back("--2--");
		b.push_back("--3--");
		//printVector(b);
		ft::vector<std::string> c = b; 
		printVector(c);
		if (!c.empty())
			std::cout << "not empty anymore" << std::endl;
	} catch(std::length_error& a) {
		std::cout << a.what() << std::endl;
	}*/
	return 0;
}
