#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumCoins(vector<int>& coins, int sum) {
    sort(coins.rbegin(), coins.rend()); 
    int count = 0;
    for (int coin : coins) {
        if (sum == 0) break;
        if (coin <= sum) {
            count += sum / coin; 
            sum %= coin;       
        }
    }
    return (sum == 0) ? count : -1;
}

int main() {
    vector<int> coins = {9, 6, 5, 1};
    int sum = 19;
    int result = minimumCoins(coins, sum);
    if (result != -1) {
        cout << "Minimum number of coins required: " << result << endl;
    } else {
        cout << "Not possible to make the change with given denominations." << endl;
    }
    return 0;
}