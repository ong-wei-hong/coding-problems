#include <iostream>

int k;

int main() {
    std::cin >> k;
    for(int i{1}; i<=k; ++i) {
        long long n {i * i}, moves {n * (n-1) / 2};
        if(i > 2)
            moves -= 4 * (i-1) * (i-2);
        std::cout << moves << '\n';
    }

    return 0;
}