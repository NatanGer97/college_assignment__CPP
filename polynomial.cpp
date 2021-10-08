//#pragma once
#include"polynomial.h"

#include <iostream>
using namespace std;

int Polynomial::maxRank_in_program = 0;
// friend func;
ostream &operator<<(ostream& cout, const Polynomial& pol_obj)
{
	// this fun print the pol obj.
	int i = 1;
	cout << "polynomial = " << pol_obj.polinomial_coeffes_arr[0]; // print the first coeff;

	while (i <= pol_obj.real_rank_pol)
	{
		cout << "+(" << pol_obj.polinomial_coeffes_arr[i] << ")*X^" << i;
		i++;
	}

	cout << "\n";
	return cout;
}  
Polynomial operator*( double num,  Polynomial& pol)
{
	Polynomial newPOl(pol.real_rank_pol);
	for (int i = 0; i <= pol.real_rank_pol; i++)
	{
		newPOl.polinomial_coeffes_arr[i] = pol.polinomial_coeffes_arr[i] *num;
	}
	return newPOl;
}  
//Polynomial &operator+(Polynomial &p1, Polynomial &p2)
//{
//	Polynomial newPOl(p1.real_rank_pol+p2.real_rank_pol);
//	for (int i = 0; i <= newPOl.real_rank_pol; i++)
//	{
//		newPOl.polinomial_coeffes_arr[i] = p1.polinomial_coeffes_arr[i] + p2.polinomial_coeffes_arr[i];
//	}
//	return newPOl;
//}

// other func;
Polynomial::Polynomial(const Polynomial& pol_obj) :biggest_pol_deg(pol_obj.biggest_pol_deg)
{
	int i = 0;
	real_rank_pol = pol_obj.real_rank_pol;
	/*delete []polinomial_coeffes_arr;*/
	polinomial_coeffes_arr = new double[pol_obj.real_rank_pol + 1];
	while (i <= pol_obj.real_rank_pol)
	{
		polinomial_coeffes_arr[i] = pol_obj.polinomial_coeffes_arr[i];
		i++;
	}

	/*pol_degree_setter();*/
}
Polynomial::Polynomial() :biggest_pol_deg(0)
{
	this->real_rank_pol = biggest_pol_deg;
	this->polinomial_coeffes_arr = new double[1];
	this->polinomial_coeffes_arr[0] = 0.0;


}
// op
Polynomial Polynomial::operator*(const Polynomial& pol)
{
	Polynomial newPol((this->real_rank_pol + pol.real_rank_pol) );
	int size = this->real_rank_pol + pol.real_rank_pol -1;
	for (int i = 0; i <= size; i++)
		newPol[i] = 0;
	for (int i = 0; i <= this->real_rank_pol; i++)
	{
		for (int j = 0; j <= pol.real_rank_pol; j++)
		{
			newPol[i + j] += this->polinomial_coeffes_arr[i] * pol.polinomial_coeffes_arr[j];
		}
	}
	newPol.pol_degree_setter();
	
	return newPol;
}
Polynomial Polynomial::operator+(const Polynomial& pol)
{
	int size = biggest_pol_deg >= pol.biggest_pol_deg ? biggest_pol_deg : pol.biggest_pol_deg;
	Polynomial newPol(size);

	for (int i = 0; i <= real_rank_pol; i++)
	{
		newPol.polinomial_coeffes_arr[i] = this->polinomial_coeffes_arr[i];
	}

	for (int i = 0; i <= pol.real_rank_pol; i++)
	{
		newPol.polinomial_coeffes_arr[i]+=pol.polinomial_coeffes_arr[i];

	}
	newPol.pol_degree_setter();
	

	
	return newPol;
}    
Polynomial Polynomial::operator-(const Polynomial& pol)
{
	int size = biggest_pol_deg >= pol.biggest_pol_deg ? biggest_pol_deg : pol.biggest_pol_deg;
	Polynomial newPol(size);

	for (int i = 0; i <= real_rank_pol; i++)
	{
		newPol.polinomial_coeffes_arr[i] = this->polinomial_coeffes_arr[i];
	}
	
	for (int i = 0; i <= pol.real_rank_pol; i++)
	{
		newPol.polinomial_coeffes_arr[i] -= pol.polinomial_coeffes_arr[i];

	}
	newPol.pol_degree_setter();



	return newPol;;
}  
Polynomial &Polynomial::operator=(const Polynomial &pol)
{
	//Polynomial newPol(pol.real_rank_pol);
	if (real_rank_pol != pol.real_rank_pol)
	{
		delete[] polinomial_coeffes_arr;

		
		polinomial_coeffes_arr = new double[pol.real_rank_pol];
		this->real_rank_pol = pol.real_rank_pol;
	}

	//delete[] polinomial_coeffes_arr;


	polinomial_coeffes_arr = new double[pol.real_rank_pol+1];
	this->real_rank_pol = pol.real_rank_pol;
	for (int i = 0; i <= this->real_rank_pol; i++)
	{
		this->polinomial_coeffes_arr[i] = pol.polinomial_coeffes_arr[i];
	}
	return *(this);
}  
double& Polynomial::operator[](int index) const 
{
	return (this->polinomial_coeffes_arr[index]);
}
double& Polynomial::operator[](int index) 
{
	return (this->polinomial_coeffes_arr[index]);
}

//
Polynomial::Polynomial(const int deg) :biggest_pol_deg(deg)
{
	/*
		"creat" pol obj with givven rank and set pol coeffes to 0
	*/
	polinomial_coeffes_arr = NULL;
	polinomial_coeffes_arr = new double[biggest_pol_deg + 1];

	int i = 0;
	while (i <= biggest_pol_deg)
	{
		polinomial_coeffes_arr[i] = 0.0;
		i++;
	}
	this->real_rank_pol = biggest_pol_deg;


}

Polynomial::Polynomial(double* list_coeffes, int const  poly_degree_max) :biggest_pol_deg(poly_degree_max)
{
	//create_pol_Coefficient(list_coeffes, biggest_pol_deg);
	polinomial_coeffes_arr = new double[biggest_pol_deg + 1];


	int i = 0;
	while (i <= biggest_pol_deg)
	{
		polinomial_coeffes_arr[i] = list_coeffes[i];
		i++;
	}
	this->real_rank_pol = biggest_pol_deg;
	pol_degree_setter();  // set currnt rank;

	

}


Polynomial::~Polynomial()
{

	if (polinomial_coeffes_arr != NULL)
	{
		delete[] this->polinomial_coeffes_arr;
	}
}
int Polynomial::getMaxDegree() { return maxRank_in_program; }  	// return max pol rank;




void Polynomial::create_pol_Coefficient(const double* coeff_list, const int rank)
{

	polinomial_coeffes_arr = new double[biggest_pol_deg + 1];


	int i = 0;
	while (i <= biggest_pol_deg)
	{
		polinomial_coeffes_arr[i] = coeff_list[i];
		i++;
	}

}
void Polynomial::pol_degree_setter()
{
	real_rank_pol = getDegree(true);


}
void Polynomial::setCoeff(const int coeff_Deg, const double coeff_num)
{
	polinomial_coeffes_arr[coeff_Deg] = coeff_num;
	pol_degree_setter();
}

int Polynomial::getDegree(bool choice)
{//return the right rank of the polynom and update the static max degree;

	if (choice == true)
	{
		// runs from the tail to the head of the arr, til fint coeff !=0 -> the right rank of pol;

		for (int temp_deg = biggest_pol_deg; temp_deg >= 0; temp_deg--)
		{
			if (polinomial_coeffes_arr[temp_deg] != 0)
			{

				Polynomial::maxRank_in_program = Polynomial::maxRank_in_program < temp_deg ? temp_deg : Polynomial::maxRank_in_program;

				return temp_deg; // the current rank of the pol' obj

			}
		}
		return 0; // return rank = 0;
	}

	else
	{
		// In case the givven value is false
		return (this->biggest_pol_deg); // return degree given in the creation.

	}

}




