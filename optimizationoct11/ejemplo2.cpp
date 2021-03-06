#include <iostream>

int main(void){
  const int M = 7000;
  const int N = 500;
  double **data = nullptr; //compilar con g++11

  data = new double *[M];
  for (int ii = 0; ii < M; ++ii){
    data[ii]=new double [N];
  }
  
  
  std::cout << data[M/2][N/2] << std::endl;

  for (int ii = 0; ii < M; ++ii){    //Siempre que usamos new debemos hacer delete
    delete [] data[ii];
  }
  delete [] data;

  return 0; 
}
