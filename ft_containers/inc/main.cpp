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

 void _testReserve() {
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

 void	testResize() {
	ft::vector<int> myvector;
	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

  	myvector.resize(5);
  	myvector.resize(8,100);
  	myvector.resize(12);

  	std::cout << "myvector contains:";
  	for (size_t i=0;i<myvector.size();i++)
    	std::cout << ' ' << myvector[i];
  	std::cout << '\n';
	std::cout << "capacity : " << myvector.capacity() << std::endl;
	std::cout << "size : " << myvector.size() << std::endl;
}

 void testGetAllocator() {
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

 void testAt() {

	ft::vector<int> myvector (10);   // 10 zero-initialized ints

  	// assign some values:
  	for (unsigned i=0; i<myvector.size(); i++)
    	myvector.at(i)=i;

  	std::cout << "myvector contains:";
  	for (size_t i=0; i<myvector.size(); i++)
    	std::cout << ' ' << myvector.at(i);
  	std::cout << '\n';
}

void	testFrontBack() {
	ft::vector<int> myvector;
	myvector.push_back(10);

	std::cout << myvector.back() << std::endl;

	while (myvector.back() != 1) {
		myvector.push_back ( myvector.back() -1 );
	}
	std::cout << "myvector contains:";
	for (unsigned i=0; i < myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << std::endl;
	std::cout << myvector.front() - myvector.back() << std::endl;
}

void	testAssign() {
	ft::vector<int> first;
  	ft::vector<int> second;
  	ft::vector<int> third;

  	first.assign (7,100);             // 7 ints with a value of 100

  	ft::vector<int>::iterator it;
	
	it = first.begin() + 1;

  	second.assign (it,first.end()-1); // the 5 central values of first

  	int myints[] = {1776,7,4};
  	third.assign (myints,myints+3);   // assigning from array.

  	std::cout << "Size of first: " << int (first.size()) << '\n';
  	std::cout << "Size of second: " << int (second.size()) << '\n';
  	std::cout << "Size of third: " << int (third.size()) << '\n';
 }

void	testErase() {
	ft::vector<int> myvector;
	std::vector<int> stdvector;

 	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) {
		myvector.push_back(i);
		stdvector.push_back(i);

	}

  	// erase the 6th element
  	myvector.erase (myvector.begin()+5);
	stdvector.erase(stdvector.begin()+5);

  	// erase the first 3 elements:
  	myvector.erase (myvector.begin(),myvector.begin()+3);
  	stdvector.erase (stdvector.begin(),stdvector.begin()+3);

  	std::cout << "std::vector contains:";
  	for (unsigned i=0; i<stdvector.size(); ++i) {
		std::cout << ' ' << stdvector[i];
 	}
  	std::cout << '\n';
  	std::cout << "ft::vector contains:";
  	for (unsigned i=0; i<myvector.size(); ++i) {
		std::cout << ' ' << myvector[i];
 	}
	std::cout << '\n';
}

void	testSwap() {
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	std::cout << "first foo size : " << foo.size() <<std::endl;
	int *ptr = foo.get_allocator().allocate(foo.size());
	std::cout << "first foo allocator : " << ptr << std::endl;
	std::cout << "first foo capacity : " << foo.capacity() << std::endl;

	std::cout << "----  -----  ----" << std::endl;

	std::cout << "first bar size : " << bar.size() <<std::endl;
	int *ptr1 = bar.get_allocator().allocate(bar.size());
	std::cout << "first bar allocator : " << ptr1 << std::endl;
	std::cout << "first bar capacity : " << bar.capacity() << std::endl;
	
	std::cout << "----  -----  ----" << std::endl;
	
	foo.swap(bar);
	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';
	
	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';

	std::cout << "second foo size: " << foo.size() <<std::endl;
	int *ptr2 = foo.get_allocator().allocate(foo.size());
	std::cout << "second foo allocator : " << ptr2 << std::endl;
	std::cout << "second foo capacity : " << foo.capacity() << std::endl;

	std::cout << "----  -----  ----" << std::endl;

	std::cout << "second bar size : " << bar.size() <<std::endl;
	int *ptr3 = bar.get_allocator().allocate(bar.size());
	std::cout << "second bar allocator : " << ptr3 << std::endl;
	std::cout << "second bar capacity : " << bar.capacity() << std::endl;
}

void	testInsert() {
	// yep... it's a Elden Ring reference.
	std::vector<std::string> bar;
	bar.push_back("TRES");
	bar.push_back("DUO");
	bar.push_back("NIHIL");
	bar.insert(bar.begin() + 2,"UNUS");
	bar.push_back("NIHIL");
	bar.insert(bar.end(), "NIIIIHIIL");
	std::cout << bar.size() << std::endl;
	std::cout << bar.capacity() << std::endl;
	for (size_t i = 0; i < bar.size(); i++)
		std::cout << bar[i] << std::endl;
	std::cout << std::endl;
	/* ... */
	ft::vector<std::string> foo;
	foo.push_back("TRES");
	foo.push_back("DUO");
	foo.push_back("NIHIL");
	foo.insert(foo.begin() + 2, 5, "UNUS");
	foo.push_back("NIHIIL");
	foo.insert(foo.end(), "NIIIIHIIL");
	printVector(foo);

}

int main() {
	testInsert();
	// insert the functions test
	return 0;
}
