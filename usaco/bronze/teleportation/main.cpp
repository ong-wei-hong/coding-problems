#include <iostream>

int a, b, x, y;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    std::cin >> a >> b >> x >> y;
    
    if(a > b)
        std::swap(a, b);
    if(x > y)
        std::swap(x, y);

    std::cout << std::min(b-a, std::abs(x-a) + std::abs(y-b));
    return 0;
}