#include <bits/stdc++.h>

int main() {

    int n;
    std::cout << "\nEnter the length of the array: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "\nEnter the elements of the array: ";
    for(int& x: arr) std::cin >> x;

    std::vector<int> length(n, 1);
    std::vector<int> prev(n, -1);

    int maxLength = 0, maxIndex = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] && length[i] < length[j] + 1) {
                length[i] = length[j] + 1;
                prev[i] = j;
            }
        }
        if(length[i] > maxLength) {
            maxLength = length[i];
            maxIndex = i;
        }
    }

    std::vector<int> lis;
    int i = maxIndex;
    while (i >= 0) {
        lis.push_back(arr[i]);
        if (prev[i] == -1) break;
        i = prev[i];
    }
    std::reverse(lis.begin(), lis.end());

    std::cout << "\nLength of Longest Increasing Subsequence: " << maxLength << "\n";
    std::cout << "\nLongest Increasing Subsequence: ";
    for(auto x: lis) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    return 0;
}