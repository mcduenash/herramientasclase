//Compile with
//g++ armadillo-time.cpp -larmadillo -std=c++11

#include <iostream>
#include <armadillo>
#include <cmath>
#include <chrono>

double solvesystem(const int & size);

int main(int argc, char** argv)
{
  const int N = atoi(argv[1]); // Repeticiones
  const int M = atoi(argv[2]); // Tamaño de la matrix

  double sum = 0, sum2 = 0;
  double time = 0;
  
  for (int i = 0; i < N; ++i) {
    arma::arma_rng::set_seed(i);
    time = solvesystem(M);
    sum  += time;
    sum2 += time*time;
  }

  double mean = sum/N;
  double sigma = std::sqrt(N*(sum2/N - mean*mean)/(N-1));

  std::cout << M*M << "\t" << mean << "\t" << sigma << std::endl;

  return 0;
}

double solvesystem(const int & size) 
{
  std::chrono::time_point<std::chrono::system_clock> start, end;

  arma::mat A = arma::randu<arma::mat>(size, size);
  arma::vec b = arma::randu<arma::vec>(size);
  
  // LU
  arma::mat P,L,U;

  start = std::chrono::system_clock::now();
  arma::lu(L, U, P, A); 
  arma::vec x = solve(trimatu(U), solve(trimatl(L), P*b) );
  end = std::chrono::system_clock::now();
  

  std::chrono::duration<double> elapsed_seconds = end - start;

  return elapsed_seconds.count();
  
}
