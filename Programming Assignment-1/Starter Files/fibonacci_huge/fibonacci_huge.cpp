#include <iostream>

long long get_fibonaccihuge(long long n, long long m) {
	if(n<=1){
		return n%m;
	}
	long long a = 0, b = 1, c;
	for(int i=2;i<=n;i++){
		c=(a+b)%m;
		a = b;
		b = c;
	}
	return c;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
}
