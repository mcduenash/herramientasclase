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

double sumat(double x,int N){
  double S=0;
  for (int i=0; i<=N ;i++){
    S+=std::pow(-1.0,i)*std::pow(x,i)/factorial(i);
  }
  return S;
}

double sumai(double x,int N){
  double S=1;
  double t=1;
  for (int i=1; i<=N ;i++){
    t*=(-x)/(i);
    S+=t;
  }
  return S;
}

int main (void){
  //  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  double x=4.2;
  int N=100;
  for (int i; i<=N;i++){
    std::cout<<i<<"\t\t"<<sumai(x,i)<<"\t"<<std::fabs(sumai(x,i)-std::exp(-x))/std::exp(-x)<<"\n";
  }
  return 0;
}
