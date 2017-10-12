#include <iostream>

int main(void){
  const int M = 7000;
  const int N = 500;
  
  std::vector<double> data;

  data.resize(M*N);

  std::cout << data[M*N/2 + N/2] << std::endl; // data.at te avisa si te sales del arreglo

  return 0; 
} 
