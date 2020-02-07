//Cam Pribulsky
//Created 4 Feb 2020

// defines int32_t and related aliases
#include <cstdint>
#include <iostream>
#include <numeric>

#ifndef _POINT_H
#define _POINT_H

class Point

	public:
		//initializes x/y to 1/1 if no value
    Point(Fraction& x, Fraction y);
		~Point(void);

		//rhs == right hand side of operator
		Point operator+(Point rhs);
		Point operator-(Point rhs);
		Point operator*(Point rhs);
		Point operator=(Point rhs);

		bool operator==(Point rhs);
		bool operator!=(Point rhs);

		Fraction& getX() { return x; }
		Fraction& getY() { return Y; }


	private:
	Fraction
			x,
			y;
};

	std::istream &operator>>(std::istream &,Point &);
	std::ostream &operator<<(std::ostream &,Point);

#endif
