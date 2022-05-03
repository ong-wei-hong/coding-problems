#include <iostream>

int main() {
    int x {}, n {};
    std::cin >> x >> n;

    int remaining {(n+1)*x};
    for(int i {0}; i<n; ++i) {
        int d {};
        std::cin >> d;
        remaining -= d;
    }

    std::cout << remaining << '\n';
    
    return 0;
}