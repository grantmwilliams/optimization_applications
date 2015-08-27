/* Interval Halving Attempt C++ (Example Program For Comparison Sake. NOT Written By Me)

Grant Williams - August 27
Version 1.0.0

*/

#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

float fun (float x)
{
    return (x*x*x - 4*x - 9);
}

void bisection (float *x, float a, float b, int *itr)
// this function performs and prints the result of one iteration 
{
    *x=(a+b)/2;
    ++(*itr);
    //std::cout << "Iteration no. " << *itr << " X = " << *x << std::endl;
}
int main ()
{

    //clock stuff
    std::clock_t start;
    double duration;
    start = std::clock();
    //stop clock stuff

    int itr = 0, maxmitr = 10000;
    float x, a = -10, b = 10, allerr = 0.000001, x1;
    bisection (&x, a, b, &itr);
    do
    {
        if (fun(a)*fun(x) < 0)
            b=x;
        else
            a=x;
        bisection (&x1, a, b, &itr);
        if (fabs(x1-x) < allerr)
        {
            std::cout << "After " << itr << " iterations, root = " << x1 << std::endl;
            
            //clock stuff again
            duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    
            std::cout<<"Elapsed time: " << duration << " seconds" << std::endl;

            return 0;
        }
        x=x1;
    }
    while (itr < maxmitr);
    std::cout << "The solution does not converge or iterations are not sufficient" << std::endl;

     //clock stuff again
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    
    std::cout<<"Elapsed time: "<< duration <<" seconds" << std::endl;
    return 1;
}
