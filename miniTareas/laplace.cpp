#include<iostream>
#include<vector>
#include<cmath>

//constants
const double DELTA = 0.05;
const int STEPS = 200;
const double Lx = 1;
const double Ly = 1.4;
const int N = int(Lx/DELTA) + 1;
const int M = int(Ly/DELTA) + 1;

typedef std::vector<double> Matrix; // alias
typedef std::vector<int> matrix;

void initial_conditions(Matrix & m, matrix & m0);
void boundary_conditions(Matrix & m, matrix & m0);
void evolve(Matrix & m, const matrix & m0);
void print(const Matrix & m);
void init_gnuplot(void);
void plot_gnuplot(const Matrix & m);


int main(int argc, char const *argv[])
{
	

	Matrix data(N*M);
	matrix m0(N*M);
	initial_conditions(data, m0);
	boundary_conditions(data, m0);

	init_gnuplot();
	for(int istep = 0; istep < STEPS; ++istep){
		evolve(data, m0);
		plot_gnuplot(data);
	}



	return 0;
}

void initial_conditions(Matrix & m, matrix & m0){
	for(int id = 0; id < M*N; ++id)
	{
		m[id] = 25.0;
		m0[id] = 0;
	}
}

void boundary_conditions(Matrix & m, matrix & m0){
	int ii = 0, jj = 0;

	ii = 0;
	for (jj = 0; jj < M-1; ++jj){
		m[ii*M + jj] = 100;
		m0[ii*M + jj] = 1;
	}

	ii = N-1;
	for (jj = 0; jj < M-1; ++jj){
		m[ii*M + jj] = 0;
		m0[ii*M + jj] = 1;
	}

	jj = 0;
	for (ii = 1; ii < N-1; ++ii){
		m[ii*M + jj] = 0;
		m0[ii*M + jj] = 1;
	}

	jj = M-1;
	for (ii = 1; ii < N-1; ++ii){
		m[ii*M + jj] = 0;
		m0[ii*M + jj] = 1;
	}


	
	ii = int(N/3);
	for (jj = int(M/4); jj < int(3*M/4); ++jj){
		m[ii*M + jj] = 75;
		m0[ii*M + jj] = 1;
	}

	ii = int(2*N/3);
	for (jj = int(M/4); jj < int(3*M/4); ++jj){
		m[ii*M + jj] = -75;
		m0[ii*M + jj] = 1;
	}

}



void evolve(Matrix & m, const matrix & m0)
{
	for(int ii=0; ii<N; ++ii) {
		for(int jj=0; jj<M; ++jj) {
			// check if boundary
			if(m0[ii*M + jj]) continue;

			// evolve non boundary
			m[ii*M+jj] = (m[(ii+1)*M + jj] +
						m[(ii-1)*M + jj] +
						m[ii*M + jj + 1] +
						m[ii*M + jj - 1] )/4.0;
    }
  }
}

void print(const Matrix & m)
{
	for(int ii=0; ii<N; ++ii) {
		for(int jj=0; jj<M; ++jj) {
			std::cout << ii*DELTA << " " << jj*DELTA << " " <<  m[ii*M + jj] << "\n";
		}
		std::cout << "\n";
	}  
}

void init_gnuplot(void)
{
	std::cout << "set contour " << std::endl;
	std::cout << "set terminal gif animate " << std::endl;
	std::cout << "set out 'anim.gif' " << std::endl;
}

void plot_gnuplot(const Matrix & m)
{
	std::cout << "splot '-' w pm3d " << std::endl;
	print(m);
	std::cout << "e" << std::endl;
}