#include <iostream>
#include <vector>

void binarySearch(std::vector<int> &v, int start, int end, int number, int &index);

int main() {

    std::vector<int> v = {1,2,3,4,5,6,7,8,9};

    std::cout << "\nNumber to find : ";
    int number;
    std::cin >> number;

    int index = 0;

    binarySearch(v, 0, v.size()-1, number, index);
    
    if(index) {
        std::cout << "\nNumber found at element " << index+1 << ".\n\n";
    } else {
        std::cout << "\nNumber not found.\n\n";
    }

    return 0;
}

void binarySearch(std::vector<int> &v, int start, int end, int number, int &index) {

    if(start >= end) return;

    int mid = start + end/2;

    if(v[mid] == number) index = mid;

    else if (v[mid] > number) {
        binarySearch(v, 0, mid-1, number, index);
    }
        
    else {
        binarySearch(v, mid+1, v.size()-1, number, index);
    }
}