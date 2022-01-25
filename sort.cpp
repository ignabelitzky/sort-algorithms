#include <iostream>
#include "sort.h"

static void swap(int a[], unsigned int b, unsigned int c) {
    int aux = a[b];
    a[b] = a[c];
    a[c] = aux;
}

static unsigned int min_pos_from(int a[], unsigned int size, unsigned int i) {
    unsigned int j = i + 1;
    int minp = i;
    while(j < size) {
        if(a[j] < a[minp]) {
            minp = j;
        }
        ++j;
    }
    return minp;
}

int generate_random_number(unsigned int to) {
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
        (std::mt19937::result_type)std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()).count() +
                (std::mt19937::result_type)
                    std::chrono::duration_cast<std::chrono::microseconds>(
                        std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    std::mt19937 gen(seed);
    std::mt19937::result_type n;
    while((n = gen()) > std::mt19937::max() - (std::mt19937::max() - 5) % to) {
        // bad value retrieved so get next one
    }
    return (n % to);
}

void selection_sort(int a[], unsigned int size) {
    unsigned int i = 0, minp = 0;
    while(i < size) {
        minp = min_pos_from(a, size, i);
        swap(a, i, minp);
        ++i;
    }
}

static void insert(int a[], unsigned int i) {
    unsigned int j = i;
    while(j > 0 && a[j] < a[j-1]) {
        swap(a, j-1, j);
        --j;
    }
}

void insertion_sort(int a[], unsigned int size) {
    for(unsigned int i = 1; i < size; ++i) {
        insert(a, i);
    }
}
