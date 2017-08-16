#include<iostream>

int main(void){
  long double under=1;
  long double over=1;
  for (int N=1;N<=16450;N++){
    under/=2.0;
    over*=2.0;
    std::cout<<N<<"\t"<<under<<"\t"<<over<<"\n";
  }
  return 0;
}
