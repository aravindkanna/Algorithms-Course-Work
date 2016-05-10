#include <iostream>

long long calc_fib(int n) {
    if (n <= 1)
        return n;

    long long a=0, b=1, c;
    for(int i=2;i<=n;i++){
    	c = a+b;
    	a = b;
    	b = c;
    }
    return c;
    //return calc_fib(n - 1) + calc_fib(n - 2);
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << calc_fib(n) << '\n';
    return 0;
}
