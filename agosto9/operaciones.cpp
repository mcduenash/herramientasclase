#include<iostream>

int main(void){
  int m=25;
  int n=7;
  std::cout<<m-8-n<<"\n";
  m=n=3;
  std::cout<<m%n<<"\n";
  std::cout<<(m%n)++<<"\n";
  std::cout<<m%++n<<"\n";
  std::cout<<++m - n--<<"\n";
  std::cout<<m<<"\t"<<n<<"\n";
  return 0;
}
