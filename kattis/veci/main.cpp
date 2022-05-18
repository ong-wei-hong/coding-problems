#include <algorithm>
#include <iostream>

int x, xs[6], l{6};

int main() {
    std::cin >> x;
    while (x) {
        xs[--l] = x % 10;
        x /= 10;
    }
    if(std::next_permutation(xs+l, xs+6)) {
        for(auto it{xs+l}; it != xs+6; ++it)
            std::cout << *it;
        std::cout << '\n';
        return 0;
    }
    std::cout << 0 << '\n';
    return 0;   
}