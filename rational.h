#pragma once

#include <iostream>
#include"polynomial.h"
using namespace std;
class rational
{
	friend ostream& operator<<(ostream&, const rational&);


public:
	rational(); // ctor without parmeters -> "defult;

	rational(Polynomial, Polynomial); // c'tor with 2  parmeters

	~rational();
	void print() const;
	rational operator*(const rational&);
	rational operator+(const rational&);
	rational& operator=(const rational&);



	Polynomial getNom() const; // return  numerator
	Polynomial getDenom()const; //return  denominator


private:
	Polynomial Pol_nom;
	Polynomial Pol_denom;
};


