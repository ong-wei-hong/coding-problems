#include <iostream>

int n, x, y;
long long r;

int main() {
    std::cin >> n;
    for(int i{0}; i<n; ++i) {
        std::cin >> y >> x;
        if(x >= y) 
            if(x % 2) 
                std::cout << static_cast<long long>(x) * x - y + 1;
            else
                std::cout << static_cast<long long>(x-1) * (x-1) + y;
        else
            if(y % 2)
                std::cout << static_cast<long long>(y-1) * (y-1) + x;
            else
                std::cout << static_cast<long long>(y) * y - x + 1;
        std::cout << '\n';
    }

    return 0;
}