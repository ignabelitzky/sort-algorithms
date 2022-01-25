#include <iostream>
#include "sort.h"

#define SIZE 500

void print_array(int a[], unsigned int size) {
    for(unsigned int i = 0; i < size; ++i) {
        if(i % 50 == 0) {
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
    unsigned int size = 500;
    unsigned int limit = 1000;
    int data[SIZE] = {0};

    generate_random_array(data, size, limit);

    std::cout << "\nPrinting unsorted array..." << std::endl;
    print_array(data, size);

    auto beginTime = std::chrono::high_resolution_clock::now();
    selection_sort(data, size);
    auto endTime = std::chrono::high_resolution_clock::now();

    std::cout << "\nPrinting sorted array..." << std::endl;
    std::cout << "SELECTION SORT" << std::endl;
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count()
        << " nanoseconds." << std::endl;
    print_array(data, size);
    std::cout << std::endl; 

    generate_random_array(data, size, limit);

    std::cout << "\n Printing unsorted array..." << std::endl;
    print_array(data, size);

    beginTime = std::chrono::high_resolution_clock::now();
    insertion_sort(data, size);
    endTime = std::chrono::high_resolution_clock::now();

    std::cout << "\nPrinting sorted array..." << std::endl;
    std::cout << "INSERTION SORT" << std::endl;
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count()
        << " nanoseconds." << std::endl;
    print_array(data, size);
    std::cout << std::endl;
    
    return 0;
}
