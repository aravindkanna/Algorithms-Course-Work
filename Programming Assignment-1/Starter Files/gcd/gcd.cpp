#include <iostream>

int gcd(int a, int b) {
  int l=0, r=0;
  if(a==b){
    return a;
  }
  if(a<b){
    l=a;
    r=b;
  }
  else{
    l=b;
    r=a;
  }
  while(1){
    int rem = b%a;
    b = a;
    a = rem;
    if(!a){
      break;
    }
  }

  return b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
