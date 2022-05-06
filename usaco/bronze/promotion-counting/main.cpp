#include <iostream>

int b[4], a[4], p[3];

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    for(int i{0}; i<4; ++i)
        std::cin >> b[i] >> a[i];

    p[2] = a[3] - b[3];
    p[1] = p[2] + a[2] - b[2];
    p[0] = p[1] + a[1] - b[1];

    std::cout << p[0] << '\n'
              << p[1] << '\n'
              << p[2] << '\n';

    return 0;
}