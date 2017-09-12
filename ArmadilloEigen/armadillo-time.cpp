//Compile with g++ armadillo-time.cpp -DARMA_DONT_USE_WRAPPER -lopenblas -llapack -std=c++11

#include <iostream>
#include <armadillo>
#include <chrono>

void solvesystem(const int & size);

int main(int argc, char** argv)
{
  const int N = atoi(argv[1]); // Repetitions
  const int M = atoi(argv[2]); // Matrix size
  const int S = atoi(argv[3]); // Seed

  arma::arma_rng::set_seed(S);

  for (int i = 0; i < N; ++i) {
    solvesystem(M);
  }  

  return 0;
}

void solvesystem(const int & size) 
{
  // std::chrono::time_point<std::chrono::system_clock> start, end;

  arma::mat A = arma::randu<arma::mat>(size, size);
  arma::vec b = arma::randu<arma::vec>(size);
  
  // Default solve
  // start1 = std::chrono::system_clock::now();
  // arma::vec y = arma::solve(A, b); // normal solve
  // end1 = std::chrono::system_clock::now();
  
  // LU
  arma::mat P,L,U;

  // start = std::chrono::system_clock::now();
  
  arma::lu(L, U, P, A); 
  arma::vec x = solve(trimatu(U), solve(trimatl(L), P*b) );
  
  // end = std::chrono::system_clock::now();
  
  // QR
  

  // Printing

  // std::chrono::duration<double> elapsed_seconds = end - start;
  // std::cout << elapsed_seconds.count() << std::endl;

  std::cout << A << std::endl;
  
  
}
