#include <bits/stdc++.h>

void LCS(std::string s1, std::string s2) {
    int m = s1.length();
    int n = s2.length();

    int maxLength = 0;
    int endIndex = 0;

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i-1;
                }
            }
        }
    }

    std::cout << "\nLength of Longest Common Substring : " << maxLength << "\n\n";

    std::string lcs = s1.substr(endIndex - maxLength + 1, maxLength);

    std::cout << "Longest Common Substring : " << lcs << "\n\n";

}

int main() {
    std::string s1, s2;
    std::cout << "\nEnter first string: ";
    std::cin >> s1;
    std::cout << "\nEnter second string: ";
    std::cin >> s2;

    LCS(s1, s2);

    return 0;
}