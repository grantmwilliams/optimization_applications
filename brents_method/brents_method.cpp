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

	double a;				// lower bound
	double b;				// upper bound
	double TOL = 0.0001;	// tolerance
	double MAX_ITER = 1000;	// maximum number of iterations

	int function = 1;		// set polynomial to find roots of & boundary conditions for that polynomial

	//example functions
	if (function == 1)
	{
		a = -1.5;
		b = 0;
		auto f = [](double x){ return (x+1) * (x+2) * (x+3); };
		brents_fun(f,a,b,TOL,MAX_ITER);
	}
	else if (function == 2)
	{
		a = -10;
		b = 10;
		auto f = [](double x){ return (x*x*x -4*x - 9); };
		brents_fun(f,a,b,TOL,MAX_ITER);
	}
	else if (function == 3)
	{
		a = -4;
		b = 3;
		auto f = [](double x){ return (x+3)*(x-1)*(x-1); };
		brents_fun(f,a,b,TOL,MAX_ITER);
	}



	//clock stuff again
	duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
	std::cout<< "Elapsed time: " << duration << " seconds" << std::endl;

	return 0;
}

















