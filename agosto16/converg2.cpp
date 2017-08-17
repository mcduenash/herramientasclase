#include<iostream>
#include<cmath>

double suma(double x, int N){
  double S=1;
  double m=1;
  for (int k=0; k<N; k++){
    m*=(-x)/(k+1);
    S+=m;
  }
  return S;
}

int main(void){
  
}
