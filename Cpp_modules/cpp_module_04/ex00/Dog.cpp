Dog::Dog(){}

Dog::Dog(const Cat& other) { *this = other; }

Dog& Dog::operator=(const Cat& other) {
	if (this != &other) {
		this->_type = other_type;
	}
	return (*this);
}

Dog::~Dog(){}

void	Dog::makeSound() { std::cout << "Oof!" << std::endl; }