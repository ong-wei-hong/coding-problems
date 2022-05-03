#include <iostream>

int n, x;
bool b[static_cast<unsigned int>(2*10e5)];

int main() {
    std::cin >> n;
    for(int i{1}; i<n; ++i) {
        std::cin >> x;
        b[x-1] = true;
    }
    for(int i{0}; i<n; ++i) {
        if(!b[i]) {
            std::cout << i+1 << '\n';
            return 0;
        }
    }
}