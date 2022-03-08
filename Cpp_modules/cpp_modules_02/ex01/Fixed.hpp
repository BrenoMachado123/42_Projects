#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _Integer;
		static const int _cInteger=8;
	public:
		Fixed();
		Fixed(const Fixed& Construct);
		Fixed(const float n);
		Fixed(const int n);
		Fixed &operator=(Fixed const &Construct);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif