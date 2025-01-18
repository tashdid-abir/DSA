#include <bits/stdc++.h>

int main() {

    int objects;
    std::cout << "\nEnter number of objects: ";
    std::cin >> objects;

    std::vector<int> weights(objects), values(objects), penalty(objects);

    for(int i = 0; i < objects; i++) {
        std::cout << "\nEnter weight of object [" << i+1 << "]: ";
        std::cin >> weights[i];

        std::cout << "Enter value of object [" << i+1 << "]: ";
        std::cin >> values[i];

        std::cout << "Enter penalty of object [" << i+1 << "]: ";
        std::cin >> penalty[i];
    }

    int capacity;
    std::cout << "\n\nEnter capacity: ";
    std::cin >> capacity;

    std::vector<std::vector<int>> dp(objects + 1, std::vector<int>(capacity + 1, 0));
    
    for(int i = 1; i <= objects; i++) {
        for(int j = 1; j <= capacity; j++) {
            if(weights[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - weights[i-1]] + values[i-1]);
            }
        }
    }

    std::cout << "\nMaximum value that can be obtained without penalty is: " << dp[objects][capacity] << std::endl;

    int i = objects, j = capacity;
    int total_profit = dp[objects][capacity];

    while(i > 0 && j > 0) {
        if(dp[i][j] == dp[i-1][j]) {
            std::cout << "\nObject [" << i << "] with weight " << weights[i-1] << " and value " << values[i-1] << " is excluded from the knapsack." << std::endl;
            total_profit -= penalty[i-1];
            i--;
        } else {
            std::cout << "\nObject [" << i << "] with weight " << weights[i-1] << " and value " << values[i-1] << " is included in the knapsack." << std::endl;
            j -= weights[i-1];
            i--;
        }
    }

    std::cout << "\nTotal profit after penalty is: " << total_profit << "\n\n";

    return 0;
}