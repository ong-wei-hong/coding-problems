#include <iostream>
#include <numeric>

int x;
bool u[41];

int main() {
    for(int i{0}; i<10; ++i) {
        std::cin >> x;
        u[x % 42] = true;
    }

    std::cout << std::accumulate(u, u+42, 0) << '\n';
    return 0;
}