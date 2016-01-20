/*******************************************************************************
* new_isd.cpp
*
* Grant Williams
*
* Version 1.0.0
* December 26, 2015
*
* Implementation of the incremental steepest descent algorithm
*
* To Compile Please use icc -std=c++11 if using intel or g++ -std=c++11 if using GCC.
*
*
*    ______ ____      ____ _____ _____    _____    _____  
*  .' ___  |_  _|    |_  _|_   _|_   _|  |_   _|  |_   _| 
* / .'   \_| \ \  /\  / /   | |   | |      | |      | |   
* | |   ____  \ \/  \/ /    | |   | |   _  | |   _  | |   
* \ `.___]  |  \  /\  /    _| |_ _| |__/ |_| |__/ |_| |_  
*  `._____.'    \/  \/    |_____|________|________|_____|                                                        
*
*
*
*******************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cstdlib>

double get_rand(double HI, double LO){

	double r3 = LO + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(HI-LO)));

	return r3;
}

double f1(double x, double y)
{
	// Beale's Function
	// minimum is at (3,0.5)
	// boundaries are [-4.5, 4.5] for x & y
	return (1.5 - x + x * y) * (1.5 - x + x * y) + (2.25 - x + x * y * y) * (2.25 - x + x * y * y) + (2.625 - x + x * y * y * y) * (2.625 - x + x * y * y * y);
}

double x_partial(double x, double y)
{
	double x_prime = (f1(x + 0.000001,y) - f1(x - 0.000001, y)) / 0.000002;
	return x_prime;
}

double y_partial(double x, double y)
{
	double y_prime = (f1(x, y + 0.000001) - f1(x, y - 0.000001)) / 0.000002;
	return y_prime;
}

bool converged(double tol, double last_fit, double fit, int iter, int max_iter, double grad)
{


}

void print_solution(double tol, double last_fit, double fit, int iter, int max_iter, double x, double y)
{
	if (std::abs(last_fit-fit) <= tol)
	{
		std::cout << "Minimum: " << fit << " x: " << x << " y: " << std::endl;
	}
	else if(max_iter == iter)
	{
		std::cout << "Maximum iterations reached. No solution or number of iterations is insufficient." std::endl;
	}
}

int main()
{
    // seed random number
    srand (static_cast <unsigned> (time(0)));

	// Declare Variables
	double tol = 0.00001; // tolerance for convergence
	double last_fit, fit;
	int iter;
	int max_iter = 1000; // maximum number of iterations


	return 0;
}
























