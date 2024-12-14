#include <bits/stdc++.h>

int fib(int n) {
    if (n <= 2) return 1;
    else return fib(n - 2) + fib(n - 1);
}

int main() {
    int n = 4;
    for (int i = n; i > 0; i--) {
        std::cout << fib(i) << " ";
    }
    return 0;
}