#include <algorithm>
#include <iostream>
#include <vector>

int x, books[100000], sum;

int main() {
    std::cin >> x;
    for(int i{0}; i<x; ++i) {
        std::cin >> books[i];
        sum += books[i];
    }

    std::sort(books, books+x);

    for(int i{x-3}; i>=0; i-=3)
        sum -= books[i];
        
    std::cout << sum;

    return 0;
}