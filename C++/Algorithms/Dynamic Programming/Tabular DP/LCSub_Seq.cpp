#include <bits/stdc++.h>

void LCS(std::string s1, std::string s2) {
    int m = s1.length();
    int n = s2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::cout << "\nLength of Longest Common Subsequence: " << dp[m][n] << "\n\n";

    std::string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    std::reverse(lcs.begin(), lcs.end());

    std::cout << "Longest Common Subsequence: " << lcs << "\n\n";
}

int main() {
    std::string s1, s2;
    std::cout << "\nEnter the first string  : ";
    std::cin >> s1;
    std::cout << "\nEnter the second string : ";
    std::cin >> s2;

    LCS(s1, s2);

    return 0;
}