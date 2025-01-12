// using one element of the array multiple times.

#include <bits/stdc++.h>

bool findsum(std::array<int,3>& n, int t) {

    if(t == 0) return true;
    if(t < 0) return false;

    for(int i = 0; i < n.size(); i++) {
        int remainder = t - n[i];
        if( findsum(n, remainder) ) return true;
    }

    return false;
}

int main() {

     std::array<int,3> n = {7,5,10};

     int targetSum = 23;

     std::cout << std::boolalpha << findsum(n,targetSum);

     return 0;
}