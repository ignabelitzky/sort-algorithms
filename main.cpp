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

void generate_random_array(int a[], unsigned int size, unsigned int limit) {
    for(unsigned int i = 0; i < size; ++i) {
        a[i] = generate_random_number(limit);
    }
}

int main() {
    unsigned int size = 100;
    unsigned int limit = 1000;
    int data[SIZE] = {0};

    generate_random_array(data, size, limit);

    std::cout << "\nPrinting unsorted array..." << std::endl;
    print_array(data, size);

    selection_sort(data, size);

    std::cout << "\nPrinting sorted array..." << std::endl;
    std::cout << "SELECTION SORT" << std::endl;
    print_array(data, size);
    std::cout << std::endl; 

    generate_random_array(data, size, limit);

    std::cout << "\n Printing unsorted array..." << std::endl;
    print_array(data, size);

    insertion_sort(data, size);

    std::cout << "\nPrinting sorted array..." << std::endl;
    std::cout << "INSERTION SORT" << std::endl;
    print_array(data, size);
    std::cout << std::endl;
    
    return 0;
}
