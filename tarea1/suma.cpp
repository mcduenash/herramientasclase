#include<iostream>

//Se crea una funcion que calcula el valor de la suma armonica como funcion de N

float suma(int N){
  float a=0;
  for (int i=1;i<=N;i++){
    a+=1.0/i;
  }
  return a;
}

//Se crea un loop para imprimir el resultado de la suma en funcion de N

int main(){
  int N=500;
  std::cout<<"N\t\tSuma"<<std::endl;
  for (int i=1;i<=N;i++){
    std::cout<<i<<"\t\t"<<suma(i)<<std::endl;
  }
  return 0;
}
