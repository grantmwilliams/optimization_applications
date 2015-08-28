/*******************************************************************************
*
* Grant Williams
*
* Version 1.0.0
* August 27, 2015
*
* Test Program for Brent's Method Function.
*
* Brent's method makes use of the bisection method, the secant method, and inverse quadratic interpolation in one algorithm.
*
* Function Contained in brent_fun.h
* To Compile Please use icc -std=c++11 if using intel or g++ -std=c++11 if using GCC.
*
********************************************************************************/

#include <iostream>
#include <ctime>
#include "brent_fun.h"

int main()
{
	//clock stuff
	std::clock_t start;
	double duration;
	start = std::clock();
	//stop clock stuff

	//Example Function
	auto f = [](double x){ return (x*x*x - 4*x - 9); };

	double a = -10;			// lower bound
	double b = 10;			// upper bound
	double TOL = 0.00001;	// tolerance
	double MAX_ITER = 1000;	// maximum number of iterations

	//double root = brent_fun(f,a,b,TOL,MAX_ITER);

	//std::cout << "The Root is: " << root << std::endl;

	//clock stuff again
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout<< "Elapsed time: " << duration << " seconds" << std::endl;

	return 0;
}

















