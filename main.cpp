#include "MergeSort.h"
#include <iostream>

int main() {
    MergeSort sorter;
    std::vector<int> data = { 38, 27, 43, 3, 9, 82, 10 };

    std::cout << "Before sorting: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sorter.sort(data);

    std::cout << "After sorting: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}