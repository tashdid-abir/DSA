#include <iostream>

void reverse_string(std::string s, int index);

int main() {

    std::string s;
    std::cout << "Please enter the string : ";
    std::getline(std::cin,s);
    reverse_string(s, s.length());
    return 0;
}

void reverse_string(std::string s, int index) {

    if(index < 0) return;
    
    else {
        std::cout << s[index-1];
        reverse_string(s, index-1);
    }

}