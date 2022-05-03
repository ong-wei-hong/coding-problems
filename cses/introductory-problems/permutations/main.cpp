#include <iostream>

int n;

int main() {
    std::cin >> n;
    if(n == 1) {
        std::cout << 1 << '\n';
        return 0;
    }
    if(n < 4) {
        std::cout << "NO SOLUTION\n";
        return 0;
    }

    for(int i {n-1}; i>0; i-=2)
        std::cout << i << ' ';
    for(int i {n}; i>0; i -=2)
        std::cout << i << ' ';

    return 0;
}