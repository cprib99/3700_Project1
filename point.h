//Cam Pribulsky
//Created 4 Feb 2020

// defines int32_t and related aliases
#include <cstdint>
#include <iostream>
#include <numeric>

#ifndef _POINT_H
#define _POINT_H

class Point
{
	public:
		//initializes x/y to 1/1 if no value
    Point(int32_t x=1, int32_t y=1);
		~Point(void);

		//rhs == right hand side of operator
		Point operator+(Point rhs);
		Point operator-(Point rhs);
		Point operator*(Point rhs);
		Point operator=(Point rhs);

		bool operator==(Point rhs);
		bool operator!=(Point rhs);

		// getter for x var
		int32_t getx()
		{
			return xPt;
		}

		// getter for y var
		int32_t gety()2
		{
			return yPt;
		}

	private:
		int32_t
			xPt,
			yPt;
};

	std::istream &operator>>(std::istream &,Point &);
	std::ostream &operator<<(std::ostream &,Point);

#endif
