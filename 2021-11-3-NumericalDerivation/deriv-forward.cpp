#include<iostream>
#include <cmath>

double fun(double x);
double fderiv(double x, double h);

int main(int argc, char const *argv[])
{
	const double x = 2.7;
	const double h = 0.1;
	std::cout.precision(15); std::cout.setf(std::ios::scientific);
	std::cout << x << "\t" << h << "\t" << fderiv(x, h) << "\t" << cos(x) << std::endl;
	return 0;
}

double fun(double x)
{
	return sin(x);
}

double fderiv(double* f, double x, double f)
{
	return (fun(x+h) - fun(x))/h;
}