#include <iostream>
int n, i{1}, x{1};

int main() {
    std::cin >> n;
    while(x < n) {
        x *= 2;
        ++i;
    }
    std::cout << i << '\n';
    return 0;
}