#ifndef CAT_HPP
# define CAT_HPP

class Cat: public Animal {
	protected:
		Cat();
	public:
		~Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		virtual void makeSound();
}


#endif