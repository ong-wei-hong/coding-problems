#include <iostream>

long long n, x, s;

int main() {
    std::cin >> n;
    for(int i{0}; i<n-1; ++i) {
        std::cin >> x;
        s += x;
    }
    std::cout << (n * (n+1) / 2) - s << '\n';
    return 0;
}