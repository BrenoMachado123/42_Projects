#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _Bits;
		static const int _cBits=8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const float n);
		Fixed(const int n);

		Fixed& operator=(Fixed const& other);
		Fixed operator+(Fixed const& other);
		Fixed operator-(Fixed const& other);
		Fixed operator*(Fixed const& other);
		Fixed operator/(Fixed const& other);

		bool operator>(Fixed const &other);
		bool operator<(Fixed const &other);
		bool operator>=(Fixed const &other);
		bool operator<=(Fixed const &other);
		bool operator==(Fixed const &other);
		bool operator!=(Fixed const &other);

		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

		static Fixed const& min(Fixed const& objA, Fixed const& objB);
		static Fixed& min(Fixed& objA, Fixed& objB);
		static Fixed& max(Fixed& objA, Fixed& objB);
		static Fixed const& max(Fixed const& objA, Fixed const& objB);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif