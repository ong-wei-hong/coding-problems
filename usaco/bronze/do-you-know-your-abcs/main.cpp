#include <algorithm>
#include <iostream>

int x[7];

int main() {
    for(int& i: x)
        std::cin >> i;

    std::sort(x, x+7);

    std::cout << x[0] << ' ' << x[1] << ' ' << x[6] - x[0] - x[1];
    return 0;
}