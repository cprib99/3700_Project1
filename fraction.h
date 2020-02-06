//Cam Pribulsky
//Created 23 Jan 2020

// defines int32_t and related aliases
#include <cstdint>
#include <iostream>
#include <numeric>

#ifndef _FRACTION_H
#define _FRACTION_H

class Fraction 
{
	public:
		//initializes num/den to 0/1 if no value
		Fraction(int32_t n=0, int32_t d=1);
		~Fraction(void);

		//rhs == right hand side of operator
		Fraction operator+(Fraction rhs);
		Fraction operator-(Fraction rhs);
		Fraction operator/(Fraction rhs);
		Fraction operator*(Fraction rhs);
		Fraction operator=(Fraction rhs);

		bool operator==(Fraction rhs);
		bool operator<=(Fraction rhs);
		bool operator>=(Fraction rhs);
		bool operator!=(Fraction rhs);
		bool operator>(Fraction rhs);
		bool operator<(Fraction rhs);

		// getter for numerator
		int32_t getNum() 
		{ 
			return num; 
		}  

		// getter for denominator
		int32_t getDen() 
		{ 
			return den; 
		}

	private:
		int32_t
			num,
			den;
};

	std::istream &operator>>(std::istream &,Fraction &);
	std::ostream &operator<<(std::ostream &,Fraction);

#endif