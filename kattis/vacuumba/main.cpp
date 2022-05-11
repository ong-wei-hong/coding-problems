#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

int n, m;
double x, y, a, b, d;

int main() {
    std::cin >> n;
    while(n--) {
        std::cin >> m;
        b = x = y = 0;
        while(m--) {
            std::cin >> a >> d;
            b += a * M_PI / 180;
            a = b + M_PI / 2;
            x += d * std::cos(a);
            y += d * std::sin(a);
        }
        std::cout << x << ' ' << y << '\n';
    }

    return 0;
}