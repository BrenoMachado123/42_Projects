Cat::Cat(){}

Cat::Cat(const Cat& other) { *this = other; }

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->_type = other_type;
	}
	return (*this);
}

Cat::~Cat(){}

void	Cat::makeSound() { std::cout << "MEOW!" << std::endl; }