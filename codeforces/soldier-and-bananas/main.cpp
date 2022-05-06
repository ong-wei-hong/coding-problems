#include <iostream>

int k, n, w;

int main() {
    std::cin >> k >> n >> w;
    std::cout << std::max(0LL, static_cast<long long>(w) * (w+1) / 2 * k - n);

    return 0;
}