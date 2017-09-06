#include<iostream>
#include<cmath>

//Definimos las funciones

double p(double x){
  return std::pow(1-x,8);
}

double q(double x){
  return 1-8*x + 28*x*x - 56*x*x*x + 70*x*x*x*x - 56*x*x*x*x*x + 28*x*x*x*x*x*x - 8*x*x*x*x*x*x*x + x*x*x*x*x*x*x*x;
}

double r(double x){
  return 1 - 8*x + 28*std::pow(x,2) - 56*std::pow(x,3) + 70*std::pow(x,4) - 56*std::pow(x,5) + 28*std::pow(x,6) - 8*std::pow(x,7) + std::pow(x,8);
}

int main (void){
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  double min=0.992 , max=1.008;
  double x=min;
  std::cout<<x<<"\t\t"<<r(x)<<"\n";//<<"\t\t"<<q(x)<<"\t\t"<<r(x)<<"\n";
  for (;;){
    x+=0.0001;
    std::cout<<x<<"\t\t"<<r(x)<<"\n";//<<"\t\t"<<q(x)<<"\t\t"<<r(x)<<"\n";
    if (x>=max){
      break;
    }
  }
  return 0;
}
