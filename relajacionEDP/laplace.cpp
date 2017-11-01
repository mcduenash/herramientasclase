#include <iostream>
#include <vector>
#include <cmath>


const double delta = 0.1;
const double L = 1.479;
const int N = int (L/delta)+1;
const int steps = 100;

typedef std::vector <double> Matrix;

void initial_conditions(Matrix & m);
void boundary_conditions(Matrix & m);
void evolve (Matrix & m);
void print (Matrix & m);

int main (void){

  Matrix data (N*N);
  initial_conditions(data);
  boundary_conditions(data);

  for (int i = 0; i < steps; ++i){
    evolve(data);
  }
  
  print (data);

  return 0;
}

void initial_conditions (Matrix & m){
  
  for (int ii = 0; ii < N; ++ii){
      for (int jj = 0; jj< N; ++jj){
	m[ii*N+jj] = 1.0;
      }
  }
}

void boundary_conditions ( Matrix & m){
  int ii = 0, jj = 0;

  ii = 0;
  for (jj = 0; jj < N; ++jj){
    m[ii*N + jj] = 100;
  }

  ii = N-1;
  for (jj = 0; jj < N; ++jj){
    m[ii*N + jj] = 0;
  }

  jj = 0;
  for (ii = 0; ii < N; ++ii){
    m[ii*N + jj] = 0;
  }

  jj = N-1;
  for (ii = 0; ii < N; ++ii){
    m[ii*N + jj] = 0;
  }
}

void evolve (Matrix & m){

  for (int ii = 0; ii<N; ++ii){
    for (int jj = 0; jj<N; ++jj){
      if(ii == 0) continue;
      if(ii == N-1) continue;
      if(jj == 0) continue;
      if(jj == N-1) continue;
      m[ii*N+jj] = (m[(ii+1)*N + jj] +
		    m[(ii-1)*N +jj] +
		    m[ii*N + jj+1] +
		    m[ii*N + jj-1])/4.0;
    }
  }

}

void print (Matrix & m){
  
  for (int ii = 0; ii < N; ++ii){
      for (int jj = 0; jj < N; ++jj){
	std::cout << ii*delta << "\t"
		  << jj*delta << "\t"
		  << m[ii*N + jj] << "\n";
      }
      std::cout << "\n";
  }
}
