#include <iostream>
#include <vector>

void merge(std::vector<int> &v, int low, int mid, int high) {

    std::vector<int> temp;

    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high) {
        if(v[left] < v[right]) {
            temp.push_back(v[left++]);
        } else {
            temp.push_back(v[right++]);
        }
    }

    while (left <= mid) {
        temp.push_back(v[left++]);
    }

    while (right <= high) {
        temp.push_back(v[right++]);
    }

    for (int i = low; i <= high; ++i) {
        v[i] = temp[i - low];
    }
}

void mergeSort(std::vector<int> &v, int low, int high) {

    if(low < high) {
        int mid = (low+high)/2;
        mergeSort(v, low, mid);
        mergeSort(v, mid+1, high); 
        merge(v, low, mid, high);
    }
}

int main() {

    std::cout << "\nEnter how many digits : ";
    int size, number;
    std::cin >> size;

    std::vector<int> v(size);

    for(int i = 0; i < v.size(); i++) {
        std::cout << "\nEnter digit " << i+1 << " : ";
        std::cin >> v[i];
    }

    std::cout << "\n\nBefore sorting list : ";

    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    mergeSort(v, 0, v.size()-1);

    std::cout << "\nAfter sorting list  : ";

    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    return 0;
}