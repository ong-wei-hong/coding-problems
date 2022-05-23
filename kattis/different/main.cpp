#include <iostream>

long long a, b;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (std::cin >> a >> b)
        std::cout << std::abs(a - b) << '\n';

    return 0;
}