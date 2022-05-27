#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

double r, x, y, d, a, s;

int main() {
    while (std::cin >> r >> x >> y) {
        d = std::sqrt(x * x + y * y);
        if (d > r) {
            std::cout << "miss\n";
            continue;
        }
        a = 2 * std::acos(d/r);
        s = r * r / 2 * (a - std::sin(a));
        std::cout << M_PI * r * r - s << ' ' << s << '\n';
    }
    return 0;
}