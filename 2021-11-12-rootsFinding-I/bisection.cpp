#include<iostream>
#include<cmath>
#include <cstdlib>

double fun(double x);
double bisection(double xl, double xu, double  eps, double f(double) );



int main(int argc, char const *argv[])
{
	std::cout.precision(16); std::cout.setf(std::ios::scientific);

	const double xl = std::atof(argv[1]);
	const double xu = std::atof(argv[2]);
	const double eps = std::atof(argv[3]);
	std::cout << bisection(xl, xu, eps, fun) << std::endl;
	return 0;
}

double fun(double x)
{
	return 9.81*(68.1)*(1 - std::exp(-x*10/68.1))/x - 40;
}

double bisection(double xl, double xu, double eps, double f(double))
{
	double xr = 0;
	int iter = 0;
	while(1)
	{	
		xr = (xu + xl)/2;
		if(std::fabs(f(xr)) <= eps) break;
		
		iter++;

		if(f(xl)*f(xr)<0)
		{
			xu = xr;
		}
		else
		{
			xl = xr;
		}
	}
	return xr;
}