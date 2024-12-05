#include <bits/stdc++.h>

const int PRIME = 101;
const int base = 256;

long long calculateHash(const std::string& str) {

    long long hashValue = 0;
    for(int i = 0; i < str.size(); i++) {
        hashValue = (hashValue * base + str[i] % PRIME);
    }

    return hashValue;
}

std::vector <int> rabinKarp(const std::string& text, const std::string& pattern) {

    std::vector<int> results;

    int textSize = text.size();
    int patternSize = pattern.size();

    if(patternSize > textSize) return;

    long long patternHash = calculateHash(pattern);
    long long textHash = calculateHash(text.substr(0, patternSize));

    // gonna start from here ( https://chatgpt.com/share/674f54d7-5818-800a-a0d4-554a8643ba6a )
}

int main() {

    std::string text = "ababcabcabababd";
    std::string pattern = "ababddddddddddddddddddddddddddddd";

    std::vector<int> indices = rabinKarp(text, pattern);

    if(!indices.empty()) {
        std::cout << "\n\nPattern found at indices : ";
        for(auto nums: indices) {
            std::cout << nums << " ";
        } 
    } else {
        std::cout << "\n\nPattern not found.\n\n";
    }
    
    std::cout << std::endl;
    return 0;
}