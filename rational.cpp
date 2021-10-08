//#pragma once
#include <iostream>
#include"rational.h"
#include"polynomial.h"
using namespace std;


ostream& operator<<(ostream& cout, const rational& obj)
{
	// print Rational obj;

	obj.print();

	return cout;
}

rational::rational() :Pol_nom(0), Pol_denom(0) { Pol_denom.setCoeff(0, 1); }

rational::rational(Polynomial up, Polynomial down) : Pol_nom(up), Pol_denom(down) {} // rational constractur;
rational::~rational() {}

rational rational::operator*(const rational& rat1)
{
	rational newRat;;
	newRat.Pol_nom = this->getNom() * rat1.getNom();
	newRat.Pol_denom = this->getDenom() * rat1.getDenom();

	return newRat;


}
rational rational::operator+(const rational& rat1)
{
	rational newRat;
	newRat.Pol_nom =this-> getNom() * rat1.getDenom() + this-> getDenom() * rat1.getNom();
	newRat.Pol_denom = this->getDenom() * rat1.getDenom();
	
	return newRat;
}   
rational& rational::operator=(const rational& rat1)
{

	
	this->Pol_nom = rat1.getNom();
	this->Pol_denom = rat1.getDenom();
	return *this;
}




Polynomial rational::getNom() const { return this->Pol_nom; }

Polynomial rational::getDenom() const { return this->Pol_denom; }

void rational::print() const
{
	// print func for rational obj
	cout << this->Pol_nom;
	cout << "--------------------------" << endl;

	cout << this->Pol_denom;
}