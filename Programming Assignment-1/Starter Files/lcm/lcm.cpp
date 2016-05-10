#include <iostream>



long long lcm(int a, int b) {
	int t1 = a, t2 = b;
	while(t1!=t2){
		if(t1>t2){
			t1 = t1 - t2;
		}
		else{
			t2 = t2 - t1;
		}
	}
	return (a*b)/t1;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
