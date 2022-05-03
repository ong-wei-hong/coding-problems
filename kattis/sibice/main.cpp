#include <cmath>
#include <iostream>

double w, h;
int n, l, x;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> w >> h;
    l = static_cast<int>(std::sqrt(w * w + h * h));
    while (n--) {
        std::cin >> x;
        std::cout << ((x <= l) ? "DA\n" : "NE\n");
    }

    return 0;
}