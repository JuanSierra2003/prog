#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <boost/numeric/odeint.hpp>

typedef std::vector<double> state_t;

void print(const state_t & y, double x);
template <class fptr>
double newton(double x0, fptr fun, double eps, int & niter);

// functor
struct Fderiv {
	double E_ = 0; //internal parameter
	void operator()(const state_t & y, state_t & dydx, double x) { //external interface, is a function
	// vector is : y = (y0, y1) = (phi, z), z = dphi/dx
		dydx[0] = y[1];
		dydx[1] = -E_*y[0];
	}
};


int main(int argc, char const *argv[])
{
	// constants
	const double E0 = atof(argv[1]);
	const double phi0 = atof(argv[2]);
	const double phidot0 = atof(argv[3]);
	const double phif = 0.0;
	const double X0 = 0.0;
	const double XF = M_PI/2;
	const double DX = 0.001;
	const double EPS = 1.0e-6;
	const int N = 2;

	state_t y(N);

	// auxiliar function
	auto faux = [&y, phi0, phidot0, phif, X0, XF, DX](double E){
		y[0] = phi0; y[1] = phidot0;
		Fderiv j; j.E_ = E; // declare functor and assing internal var E  to lambda argument
		boost::numeric::odeint::integrate(j, y, X0, XF, DX);
		return y[0] - phif;};

	// apply newton-rapson
	int nsteps = 0;
	double E = newton(E0, faux, EPS, nsteps);

	// print solution
	y[0] = phi0; y[1] = phidot0;
	Fderiv k; k.E_ = E;
	boost::numeric::odeint::integrate(k, y, X0, XF, DX, print);

	std::cerr << E << std::endl;


	return 0;
}

void print(const state_t & y, double x)
{
  std::cout << x << "\t" << y[0] << "\t" << y[1] << std::endl;
}

template <class fptr>
double newton(double x0, fptr fun, double eps, int & niter)
{
  double h = 0.00001;
  double xr = x0;
  int iter = 1;
  while(std::fabs(fun(xr)) > eps) {
    double fderiv =  (fun(xr+h/2) - fun(xr-h/2))/h;
    xr = xr - fun(xr)/fderiv;
    iter++;
  }
  niter = iter;
  return xr;
}
