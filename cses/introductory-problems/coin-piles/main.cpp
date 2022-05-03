#include <iostream>

int n;
int a, b, x, y, z;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n;
    while(n--) {
        std::cin >> a >> b;
        x = std::max(a, b);
        y = std::min(a, b);
        z = x - y;
        x -= 2 * z;
        y -= z;
        if(x >= 0 && y >= 0 && x % 3 == 0 && y % 3 == 0)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}