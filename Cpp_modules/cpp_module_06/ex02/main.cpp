#include "Base.hpp"
#include "Childs.hpp"

int main() {
	{
		Base *random = generate();
		Base & ref = *random;

		identify(random);
		identify(ref);

		std::cout << std::endl;

		delete random;
	}
	{
		//unknown type of base test
		Base *random = new D();
		Base & ref = *random;

		identify(random);
		identify(ref);

		delete random;
	}
	return 0;
}
