#include <iostream>

long long n;

int main() {
    std::cin >> n;
    std::cout << n;
    while (n != 1) {
        if (n & 1)
            n = 3 * n + 1;
        else
            n >>= 1;
        std::cout << ' ' << n;
    }

    return 0;
}