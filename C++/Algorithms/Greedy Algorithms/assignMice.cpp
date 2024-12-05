#include <bits/stdc++.h>

int main() {

    int max = 0, value = 0;

    std::vector<int> position = {5,6,-1,0,3};
    std::vector<int> hole = {-7,0,4,2,5};

    sort(position.begin(), position.end());
    sort(hole.begin(), hole.end());

    for(int i = 0; i < position.size(); i++) {
        value = abs(position[i]-hole[i]);
        if(max < value) max = value;
    }

    std::cout << max;

    return 0;
}