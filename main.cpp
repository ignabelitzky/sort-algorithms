#include <iostream>
#include <chrono>
#include <random>
#include <array>

#define SIZE 500

template <typename T, std::size_t size>
static void swap(std::array<T, size>& a, unsigned int b, unsigned int c) {
    int aux = a[b];
    a[b] = a[c];
    a[c] = aux;
}

template <typename T, std::size_t size>
static unsigned int min_pos_from(std::array<T, size>& a, unsigned int i) {
    unsigned int j = i + 1u;
    unsigned int minp = i;
    while(j < a.size()) {
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

template <typename T, std::size_t size>
void selection_sort(std::array<T, size>& a) {
    unsigned int i = 0u, minp = 0u;
    while(i < a.size()) {
        minp = min_pos_from(a, i);
        swap(a, i, minp);
        ++i;
    }
}

template <typename T, std::size_t size>
static void insert(std::array<T, size>& a, unsigned int i) {
    unsigned int j = i;
    while(j > 0 && a.at(j) < a.at(j-1)) {
        swap(a, j-1, j);
        --j;
    }
}

template <typename T, std::size_t size>
void insertion_sort(std::array<T, size>& a) {
    for(unsigned int i = 1u; i < a.size(); ++i) {
        insert(a, i);
    }
}

template <typename T, std::size_t size>
void print_array(std::array<T, size>& a) {
    for(unsigned int i = 0; i < a.size(); ++i) {
        if(i % 50 == 0) {
            std::cout << std::endl;
        }
        std::cout << a.at(i) << " ";
    }
    std::cout << std::endl;
}

template <typename T, std::size_t size>
void generate_random_array(std::array<T, size>& a, unsigned int limit) {
    for(unsigned int i = 0; i < a.size(); ++i) {
        a[i] = generate_random_number(limit);
    }
}

int main() {
    unsigned int limit = 1000;
    std::array<int, SIZE> data = {0};

    generate_random_array(data, limit);

    std::cout << "\nPrinting unsorted array..." << std::endl;
    print_array(data);

    auto beginTime = std::chrono::high_resolution_clock::now();
    selection_sort(data);
    auto endTime = std::chrono::high_resolution_clock::now();

    std::cout << "\nPrinting sorted array..." << std::endl;
    std::cout << "SELECTION SORT" << std::endl;
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count()
        << " nanoseconds." << std::endl;
    print_array(data);
    std::cout << std::endl; 

    generate_random_array(data, limit);

    std::cout << "\nPrinting unsorted array..." << std::endl;
    print_array(data);

    beginTime = std::chrono::high_resolution_clock::now();
    insertion_sort(data);
    endTime = std::chrono::high_resolution_clock::now();

    std::cout << "\nPrinting sorted array..." << std::endl;
    std::cout << "INSERTION SORT" << std::endl;
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count()
        << " nanoseconds." << std::endl;
    print_array(data);
    std::cout << std::endl;

    return 0;
}
