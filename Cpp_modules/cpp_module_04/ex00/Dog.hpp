#ifndef DOG_HPP
# define DOG_HPP

class Dog: public Animal {
	protected:
		std::string type;
	public:
		~Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		virtual void makeSound();
		void makeSound();
}

#endif