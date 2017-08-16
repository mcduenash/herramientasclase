#include<iostream>
#include<cstdlib>

typedef long double REAL;

int main(int argc, char **argv){
  int P=std::atoi(argv[1]);
  REAL eps=1;
  for(int N=1;N<=P;N++){
    eps/=2;
    REAL one=1+eps;
    std::cout<<N<<"\t"<<one<<"\t"<<eps<<"\n";
  }
  return 0;
}
			    
