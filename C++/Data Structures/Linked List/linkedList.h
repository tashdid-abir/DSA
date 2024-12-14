#include <iostream>

int mainZ() {

    int t;
    std::cin >> t;

    while(t--) {
        int a,b,c;
        std::cin >> a >> b >> c;

        if(a + b >= 10 || b + c >= 10 || c + a >= 10) std::cout << "Yes\n";
        else std::cout << "No";
    }
}