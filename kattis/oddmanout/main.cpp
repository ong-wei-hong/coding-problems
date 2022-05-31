#include <iostream>

int x, n, g, c, i;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    while(i < n) {
        std::cin >> g;
        x = 0;
        while(g--) {
            std::cin >> c;
            x ^= c;
        }
        std::cout << "Case #" << ++i << ": " << x << '\n';
    }
    return 0;
}