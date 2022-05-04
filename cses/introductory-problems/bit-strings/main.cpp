#include <cmath>
#include <iostream>

int n, mod {static_cast<int>(1e9+7)};
long long result{1L}, x{2L};

int main() {
    std::cin >> n;
    while(n)
        if (n & 1) {
            result = (result * x) % mod;
            --n;
        } else {
            x = (x * x) % mod;
            n >>= 1;
        }
            
    std::cout << result << '\n';

    return 0;
}