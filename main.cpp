#include <iostream>
#include "sort.h"

#define SIZE 100

void print_array(int a[], unsigned int size) {
    for(unsigned int i = 0; i < size; ++i) {
        if(i % 10 == 0) {
            std::cout << std::endl;
        }
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    unsigned int size = 100;
    unsigned int limit = 1000;
    int data[SIZE] = {0};
    for(unsigned int i = 0; i < size; ++i) {
        data[i] = generate_random_number(limit);
    }
    std::cout << "\nPrinting unsorted array..." << std::endl;
    print_array(data, size);
    selection_sort(data, size);
    std::cout << "\n\nPrinting sorted array..." << std::endl;
    std::cout << "SELECTION SORT" << std::endl;
    print_array(data, size);
    std::cout << std::endl; 
    
    return 0;
}
