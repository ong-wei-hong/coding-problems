#include <iostream>
#include <iomanip>

int c, r;
double v;

int main() {
    std::cin >> r >> c;
    v = 1.0 * (r - c) / r;
    std::cout << std::setprecision(10) << v * v * 100 << '\n';
}