#include <iostream>

int n, ans;
bool x, y, z;

int main() {
    std::cin >> n;
    while(n--) {
        std::cin >> x >> y >> z;
        ans += (x && y) || (y && z) || (x && z);
    }
    std::cout << ans;
    return 0;
}