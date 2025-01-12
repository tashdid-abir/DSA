#include <bits/stdc++.h>

long long fib(int n, std::unordered_map<int,long long>& memo) {

    if (n <= 2) return 1;
    if(memo.count(n)) return memo[n];
    memo[n] = fib(n - 2, memo) + fib(n - 1, memo);
    return memo[n];
}

int main() {

    int n;
    std::cin >> n;
    std::unordered_map<int,long long> memo;
    for (int i = 1; i <= n; i++) {
        std::cout << fib(i, memo) << " ";
    }
    return 0;
}