#pragma once


#include <iostream>


using namespace std;


class Polynomial
{
	friend ostream &operator<<(ostream&, const Polynomial& pol_to_print); // operator overloading for printing polinomial obj
	friend Polynomial operator*( double num,  Polynomial&);
	//friend Polynomial &operator+(Polynomial &p1, Polynomial &p2);

public:
	Polynomial(); //  the defult ctor ->"make" an empty polinom obj
	Polynomial(const Polynomial&);
	Polynomial(const int); // sets the maximun degrre of the current polynom obj
	Polynomial(double*, const int); // set the coeffes of the polynom obj  with the given rank;
	int static getMaxDegree(); // static function for static var that  holds the max rank of the pol obj in the program and return the max rank
	Polynomial operator*(const Polynomial&);
	Polynomial operator+(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	Polynomial &operator=(const Polynomial&);
	double& operator[](int) const;
	double& operator[](int);
	



	int getDegree(bool); // return the rank of the poly' obj : true- the right rank, flase - the rank of the pol' that givven in his first creation.
	void setCoeff(const int, double);
	void create_pol_Coefficient(const double*, const int);





	// distractor;
	~Polynomial();

private:
	static int maxRank_in_program; //var that holds the bigest rank in the program.

	void pol_degree_setter(); //update the right rank of current pol. and update the sataic max rank of polinomes;
	int real_rank_pol = 0;//  current rank of the pol.
	const   int biggest_pol_deg = 0; // holds the max rank of the pol obj
	double* polinomial_coeffes_arr  = NULL; // hold the coeffes of the pol obj in arr;



};


