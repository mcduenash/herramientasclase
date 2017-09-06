#include<iostream>
#include<cstdio>
#include<gsl/gsl_sf_bessel.h>

int main (void){

  double xmin=0, xmax=160, paso=0.01;
  int N=(xmax-xmin)/paso;
  for (int i=0;i<=N;i++){
    double x=xmin+i*paso;
    double y=gsl_sf_bessel_J0 (x);
    std::printf("%20.16e   %20.16e\n",x,y);
  }
  return 0;
}
