#include <cmath>
#include <iomanip>
#include <iostream>

long long x;

int main() {
    std::cin >> x;
    std::cout << std::setprecision(10) << 4.0 * std::sqrt(x) << '\n';
    return 0;
}