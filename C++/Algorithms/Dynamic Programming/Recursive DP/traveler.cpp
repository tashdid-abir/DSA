#include <bits/stdc++.h>

long long grid(int r, int c, std::unordered_map<std::string, long long>& memo) {
    
    const std::string key = std::to_string(r) + "," + std::to_string(c);
    if(r == 0 || c == 0) return 0;
    if(r == 1 && c == 1) return 1;
    if(memo.count(key)) return memo[key];
    memo[key] = grid(r-1, c, memo) + grid(r, c-1, memo);
    return memo[key];
}

int main() {

    int r,c;
    std::cin >> r >> c;

    std::unordered_map<std::string ,long long> memo;
    std::cout << grid(r, c, memo);

    return 0;
}