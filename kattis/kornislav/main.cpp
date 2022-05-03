#include <algorithm>
#include <iostream>

int sides[4];

int main() {
    for(int& i: sides)
        std::cin >> i;

    std::sort(sides, sides+4);

    std::cout << sides[0] * sides[2] << '\n';
    return 0;
}