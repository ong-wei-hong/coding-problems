#include <iostream>

int x, r, n;
bool rooms [100];

int main() {
    std::cin >> r >> n;

    for(int i{0}; i < n; ++i) {
        std::cin >> x;
        rooms[x-1] = true;
    }

    for(int i{0}; i<r; ++i)
        if(!rooms[i]) {
            std::cout << i+1 << '\n';
            return 0;
        }

    std::cout << "too late\n";
    return 0;
}