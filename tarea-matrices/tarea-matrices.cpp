#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <fstream>

void multiply(const std::vector<double> & m1, const std::vector<double> & m2, std::vector<double> & m3);

int main(int argc, char **argv) {
  // read parameters
  const int N = std::atoi(argv[1]);
  const int SEED = std::atoi(argv[2]);

  const int Pmax = 10;
  const int Pmin = 2;

  std::cout.precision(16); std::cout.setf(std::ios::scientific);

  // data structs
  std::vector<double> A(N*N, 0.0), B(N*N, 0.0), C(N*N, 0.0);

  // fill matrices A and B, using random numbers betwwen 0 and 1
  std::mt19937 gen(SEED);
  std::uniform_real_distribution<> dist(0.,1.);
  // lambda function: a local function that captures [] something, receives something (), and return something {}
  // See: https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
  std::generate(A.begin(), A.end(), [&gen, &dist](){ return dist(gen); }); // uses a lambda function
  std::generate(B.begin(), B.end(), [&gen, &dist](){ return dist(gen); }); // uses a lambda function

  // multiply the matrices A and B and save the result into C. Measure time
  auto start = std::chrono::high_resolution_clock::now();
  multiply(A, B, C);
  auto stop = std::chrono::high_resolution_clock::now();

  // use the matrix to avoid the compiler removing it
  std::cout << C[N/2] << std::endl;

  // print time
  auto elapsed = std::chrono::duration<double>(stop - start);
  std::cout << elapsed.count() << "\n";

  //ploting
  std::ofstream plot_data;
  plot_data.open("plot_data.txt");

  std::vector<double> X, Y;

  for(int p = Pmin; p < Pmax; p++)
  {
    // data structs
    std::vector<double> A1(std::pow(2,2*p), 0.0), A2(std::pow(2,2*p), 0.0), A3(std::pow(2,2*p), 0.0);

    std::generate(A1.begin(), A1.end(), [&gen, &dist](){ return dist(gen); }); 
    std::generate(A2.begin(), A2.end(), [&gen, &dist](){ return dist(gen); }); 
    std::generate(A3.begin(), A3.end(), [&gen, &dist](){ return dist(gen); }); 

    auto start = std::chrono::high_resolution_clock::now();
    multiply(A1, A2, A3);
    auto stop = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration<double>(stop - start);
    X.push_back(std::pow(2,p));
    Y.push_back(elapsed.count());
  }

  //Normalize
  double tmp = Y[0];
  for(auto & y : Y)
  {
    y /= tmp;
  }

  //writing
  for(int id = 0; id < Pmax - Pmin; id++)
  {
    plot_data << X[id] << "\t" << Y[id] << "\n";
  }

  /* La grafica con ejes logaritmicos muestra lo que parece una recta con pendiente
  entre 2 y 3, como observacion se puede decir que el tiempo de ejecucion crece a lo
  mas con N^3 */

  return 0;
}

// implementations
void multiply(const std::vector<double> & m1, const std::vector<double> & m2, std::vector<double> & m3)
{
  const int N = std::sqrt(m1.size()); // assumes square matrices
  for(int id = 0; id < N*N; id++)
  {
    for(int tmp = 0; tmp < N; tmp++)
    {
      m3[id] += m1[(id/N)*N + tmp]*m2[tmp*N + id%N]; //using: i = id/N ; j = id%N ; id = iN + j
    }
  }
}
