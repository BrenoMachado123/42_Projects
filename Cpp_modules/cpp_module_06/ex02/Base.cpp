#include "Base.hpp"

//toDo() {
//	create the * identify function and & identify Function 
//}

Base* generate() {
	Base *ptr = NULL;
	srand((unsigned int)time(NULL));
	int n = rand() % 3; // create a random number between 0 and 3
	switch (n) {
		case 0:
			ptr = new A(); break ; // create a class pointer;
		case 1:
			ptr = new B(); break ;
		case 2:
			ptr = new C(); break;
	}
	return (ptr); // return the pointer;
}
