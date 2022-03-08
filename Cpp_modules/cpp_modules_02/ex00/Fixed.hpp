#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _Integer;
		static const int _cInteger=8;
	public:
		Fixed();
		Fixed(Fixed const &Construct);
		Fixed &operator=(Fixed const &Construct);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif