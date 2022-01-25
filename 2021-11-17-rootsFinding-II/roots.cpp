#include <iostream>
#include <cmath>
#include <cstdlib>

using fptr = double(double);
double f(double x);
double bisection(double xl, double xu, fptr fun, double eps, int & niter);
double regulaFalsi(double xl, double xu, fptr fun, double eps, int & niter);
double newton(double x0, fptr fun, double eps, int & niter);

int main(int argc, char **argv)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  
  const double XL = std::atof(argv[1]);
  const double XU = std::atof(argv[2]);
  const double EPS = std::atof(argv[3]);
  int counter = 0;
  std::cout << bisection(XL, XU, f, EPS, counter) << std::endl;
  std::cout << counter << std::endl;
  std::cout << regulaFalsi(XL, XU, f, EPS, counter) << std::endl;
  std::cout << counter << std::endl;
  std::cout << newton(XU, f, EPS, counter) << std::endl;
  std::cout << counter << std::endl;

  return 0;
}

double f(double x)
{
  return 9.81*(68.1)*(1 - std::exp(-x*10/68.1))/x - 40;
}

double dev_central(double x, double h, fptr fun)
{
  return (fun(x+h/2) - fun(x-h/2))/(h);
}

template <typename algptr>
double dev_richardson(double x, double h, fptr fun, algptr algo)
{
    double val1 = algo(x, h, fun);
    double val2 = algo(x, h/2, fun);
    return (4*val2 - val1)/3;
}

double bisection(double xl, double xu, fptr fun, double eps, int & niter)
{
  double xr = xl;
  int iter = 1;
  while(std::fabs(fun(xr)) > eps) {
    if (fun(xr)*fun(xl) < 0) {
      xu = xr;
    } else {
      xl = xr;
    }
    xr = (xl + xu)/2; // bisection
    iter++;
  }
  niter = iter;
  return xr;
}

double regulaFalsi(double xl, double xu, fptr fun, double eps, int & niter)
{
  double xr = xl;
  int iter = 1;
  while(std::fabs(fun(xr)) > eps) {
    if (fun(xr)*fun(xl) < 0) {
      xu = xr;
    } else {
      xl = xr;
    }
    xr = xu - fun(xu)*(xl - xu)/(fun(xl)-fun(xu)); // bisection
    iter++;
  }
  niter = iter;
  return xr;
}

double newton(double x0, fptr fun, double eps, int & niter)
{
  double h = 0.001;
  double xr = x0;
  int iter = 1;
  while(std::fabs(fun(xr)) > eps) {
    xr -= fun(xr)/dev_central(xr, h, fun); 
    iter++;
  }
  niter = iter;
  return xr;
}