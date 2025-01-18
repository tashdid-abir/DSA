#include <bits/stdc++.h>

int main() {

    int n, target;

    std::cout << "\nEnter the target sum : ";
    std::cin >> target;

    std::cout << "\nEnter the number of elements in the array : ";
    std::cin >> n;

    std::vector<int> arr(n);

    std::cout << "\nEnter the elements of the array : ";
    for(int& x: arr) std::cin >> x;

    std::vector<std::vector<int>> dp(n+1, std::vector<int>(target+1, 0));

    for(int i = 0; i <=n; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=target; j++) {
            if(arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if(dp[n][target]) {

        std::cout << "\nThere exists a subset with the given sum.\n\n";
        
        std::vector<int> subset;
        int i = n, j = target;
        while(i > 0 && j > 0) {
            if(dp[i][j] == dp[i-1][j]) {
                i--;
            } else {
                subset.push_back(arr[i-1]);
                j -= arr[i-1];
                i--;
            }
        }

        std::cout << "The subset with the given sum is : ";
        for(int i = subset.size()-1; i >= 0; i--) {
            std::cout << subset[i] << " ";
        }
        std::cout << "\n\n";
    } else {
        std::cout << "\nThere does not exist a subset with the given sum.\n\n";
    }

    return 0;
}