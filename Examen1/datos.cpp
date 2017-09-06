#include<iostream>
#include<cmath>

//Definimos las dos funciones

double S(double a, double b, double c){
  double d=(a+b+c)/2.0;
  double A=std::sqrt(d*(d-a)*(d-b)*(d-c));
  return A;
}

double Sp(double a, double b, double c){
  double T=(1.0/4.0)*std::sqrt((a+(b+c))*(c-(a-b))*(c+(a-b))*(a+(b-c)));
  return T;
}

//Aplicamos funciones en la funcion principal para imprimir tabla

int main(void){
  double b=3;
  double c=4;
  int N=100;
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  for (int i;i<=N;i++){
    double theta=(M_PI/2.0)*std::pow(1.1,-i);
    double a=std::sqrt(std::pow(b,2)+std::pow(c,2)-2*b*c*std::cos(theta));
    std::cout<<i<<"\t\t"<<std::fabs(Sp(a,b,c)-S(a,b,c))/Sp(a,b,c)<<"\n";
  }
  return 0;
}
