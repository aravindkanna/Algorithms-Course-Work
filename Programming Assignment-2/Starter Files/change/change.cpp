//Submitted
#include <iostream>

int get_change(int n) {
  //write your code here
	int num = 0;
	while(n >= 10){
		n = n-10;
		num++;
	}
	while(n >= 5){
		n = n-5;
		num++;
	}
	while(n >=1){
		n = n-1;
		num++;
	}
  return num;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
