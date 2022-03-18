Animal::Animal(){}

Animal::Animal(const Animal& other) { *this = other; }

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->_type = other_type;
	}
	return (*this);
}

Animal::~Animal(){}

void	Animal::makeSound() { std::cout << "BrainzzzZZZ" << std::endl; }
