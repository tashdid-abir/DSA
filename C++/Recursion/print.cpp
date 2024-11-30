#include <iostream>

void print_r(int n);

int main() {

    int n;
    std::cin >> n;
    print_r(n);
    return 0;
}

void print_r(int n) {
    
    if(n == 0) return;
    else {
        print_r(n-1);
        std::cout << "I love Recursion\n";
    }
}