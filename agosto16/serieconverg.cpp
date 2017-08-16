//Este programa saca una tabla de datos que graficados muestran para que N converge la expansion de Taylor de la funcion exponencial

#include<iostream>
#include<cmath>

int factorial(int m){
  if (m==0){
    return 1;
  }
  else{
    int f=1;
    for (int i=1; i<=m; i++){
      f*=i;
    }
    return f;
  }
}

double suma(double x,int N){
  double S=0;
  for (int i=0; i<=N ;i++){
    S+=std::pow(-1.0,i)*std::pow(x,i)/factorial(i);
  }
  return S;
}

int main (void){
  for (int i; i<=100;i++){
    std::cout<<i<<"\t"<<suma(100.0,i)<<"\n";
  }
  return 0;
}
