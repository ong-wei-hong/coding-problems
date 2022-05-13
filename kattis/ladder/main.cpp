#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

int x, a;

int main() {
    std::cin >> x >> a;
    std::cout << std::ceil(x / std::sin(a * M_PI / 180));
}