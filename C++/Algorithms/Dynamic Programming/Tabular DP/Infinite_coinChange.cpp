#include <bits/stdc++.h>

int main() {
    int n;
    std::cout << "\nEnter number of coins: ";
    std::cin >> n;

    std::vector<int> coins(n);

    std::cout  << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << "Enter value of coin [" << i+1 << "]: ";
        std::cin >> coins[i];
    }

    int amount;
    std::cout << "\nEnter amount: ";
    std::cin >> amount;

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, 0));

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(coins[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
            }
        }
    }

    if(dp[n][amount]) {
        std::cout << "\nNumber of ways to make change for amount : " << amount << " is " << dp[n][amount] << std::endl;
    } else {
        std::cout << "\nNo way to make change for amount " << amount << std::endl;
    }

    std::cout << std::endl;

    return 0;
}