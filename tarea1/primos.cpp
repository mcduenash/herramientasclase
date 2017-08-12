#include<iostream>
#include<cmath>

//Se creo una funcion que permite saber si el numero ingresado es primo. La funcion retorna 0 si el numero es primo y 1 si el numero no es primo.

int primos(int n){
  int a=0;
  for(int i=2;i<=sqrt(n);i++){
    if (n%i==0){
      a=1;
      break;
    }
  }
  return a;
}

//Se creo un loop para poder imprimir los numeros primos entre el 500 y el 1400.

int main(){
  for (int p=500;p<=1400;p++){
    if(primos(p)==0){
      std::cout<<p<<std::endl;
    }
  }
  return 0;
}
