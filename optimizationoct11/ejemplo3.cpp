#include <iostream>

int main(void){
  const int M = 7000;
  const int N = 500;
  double *data = nullptr; //compilar con g++11

  
  data = new double [M*N];

  //[id][jd] -> id*N + jd (N numero de columnas)
  
  std::cout << data[M*N/2+N/2] << std::endl;


  //Siempre que usamos new debemos hacer delete

  delete [] data;

  return 0; 
}
