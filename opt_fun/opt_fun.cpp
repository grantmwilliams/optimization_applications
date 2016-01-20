/*******************************************************************************
* opt_fun.cpp
*
* Grant Williams
*
* Version 1.0.0
* October 18, 2015
*
* Test Optimization Functions
*
* To Compile Please use icc -std=c++11 if using intel or g++ -std=c++11 if using GCC.
*
*******************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm> 

/* Ackley's Function */
double f1(double x, double y)
{
	// x: {-40, 40} | y: {-40,40}
	return (-20 * std::exp(-0.2 * std::sqrt(0.5 * (x * x + y * y))) - exp(0.5 * (std::cos(2 * M_PI * x) + cos(2 * M_PI * y))) + std::exp(1) + 20);
}

/* Sphere Function NEEDS FURTHER TESTING*/
double f2(std::vector<double> x)
{
	// The function is usually evaluated on the hypercube xi ∈ [-5.12, 5.12], for all i = 1, 2, ..., d
	double sum;

	for (int i = 1; i <= x.size(); i++)
	{
		sum += x[i-1] * x[i-1];
	}

	return sum;
}
/* Rosenbrock function NEEDS TESTING */
double f3(std::vector<double> x)
{
	double sum;

	for (int i = 1; i <= x.size() - 1; i++)
	{
		sum += (100 * (x[i] - x[i-1] * x[i-1]) * (x[i] - x[i-1] * x[i-1]) + (x[i-1] * x[i-1]));
	}

	return sum;
}

/* Beale's Function */
double f4(double x, double y)
{

	return (1.5 - x + x * y) * (1.5 - x + x * y) + (2.25 - x + x * y * y) * (2.25 - x + x * y * y) + (2.625 - x + x * y * y * y) * (2.625 - x + x * y * y * y);
}

/* goldstein price function */
double f5(double x, double y)
{
	return ((1+(x + y + 1)*(x + y + 1)*(19 - 14 * x + 3 * x * x - 14 * y + 6 * x * y + 3 * y * y))*(30+(2 * x - 3 * y)*(2 * x - 3 * y)*(18 - 32 * x + 12 * x * x + 48 * y - 36 * x * y + 27 * y * y)));
}

double f6(double x, double y)
{
	return (x + 2 * y - 7) * (x + 2 * y - 7) + (2 * x + y - 5) * (2 * x + y - 5);
}

int main()
{

	double x = 3;
	double y = 0.5;

	std::cout << std::endl;

	std::cout << f4(x,y) << std::endl;

	std::cout << std::endl;
	return 0;
}










