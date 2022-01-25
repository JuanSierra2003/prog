#include <cmath>
#include <iostream>

// definition
using fptr = double(double);
double U(double x, double y);
double Fdr(double x);
double trapezoid(double a, double b, int N, fptr f);
double simpson13(double a, double b, int N, fptr f);
template <typename typealg>
double richardson(double a, double b, int N, fptr f, typealg alg);

// main
int main(int argc, char **argv)
{

  std::cout.precision(15); std::cout.setf(std::ios::scientific);

  const double masa = 1.25;
  const int N[2] = {10, 1000};
  const double rapidezReal = std::sqrt(2*(U(0, 0) - U(4, 0))/masa);


  /*
  1/2(mv**2) = W
  v = sqrt(2*W/m)
  */

  double deltaTrap = 0;
  double deltaSimp = 0;

  for(int ii = 0; ii < 2; ++ii)
  {
    deltaTrap = std::fabs(1 - std::sqrt(2*richardson(0, 1, N[ii], Fdr, trapezoid)/masa)/rapidezReal);
    deltaSimp = std::fabs(1 - std::sqrt(2*richardson(0, 1, N[ii], Fdr, simpson13)/masa)/rapidezReal);
    std::cout << N[ii] << '\t' << deltaTrap << '\t' << deltaSimp << std::endl;
  }
  
  return 0;
}

// implementation

//Potencial
double U(double x, double y)
{
  return -2*std::sin(x) + 2*x*std::cos(x) +24*y;
}

/*
d = (4,0)  camino: r = (4t,0); dr = (4,0)dt; 0 <= t <= 1
F = (2xsin(x),0)
dW = F.dr = (2*4t*sin(4t),0).(4,0)dt = 32*t*sin(4*t)dt
*/

//Diferencial de trabajo
double Fdr(double t)
{
    return 32*t*std::sin(4*t);
}

double trapezoid(double a, double b, int N, fptr f)
{
  const double h = (b-a)/N;
  double result = 0.0;

  for(int ii = 1; ii <= N-1; ++ii)
  {
    result += f(a + ii*h);
  }

  result += 0.5*(f(a) + f(b));
  result *= h;

  return result;
}

double simpson13(double a, double b, int N, fptr f)
{
  const double h = (b-a)/N;
  double result = 0.0;

  for(int ii = 1; ii <= (N/2 - 1); ++ii)
  {
    result += 2*f(a + 2*ii*h);
  }

   for(int ii = 1; ii <= N/2; ++ii)
  {
    result += 4*f(a + (2*ii - 1)*h);
  }

  result += (f(a) + f(b));
  result *= h/3;

  return result;
}


//N = 2*N <==> h = h/2
template <typename typealg>
double richardson(double a, double b, int N, fptr f, typealg alg)
{
  double val1 = alg(a, b, N, f);
  double val2 = alg(a, b, 2*N, f);
  return (4*val2 - val1)/3;
}