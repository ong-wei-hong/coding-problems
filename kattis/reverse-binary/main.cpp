#include <iostream>

int n, i, x;
bool binary[30];

int main() {
    std::cin >> n;
    while (n) {
        binary[i++] = n & true;
        n >>= 1;
    }
    
    for(int j {0}; j < i; ++j)
        if(binary[j])
            x += (1 << (i - j - 1));

    std::cout << x << '\n';

    return 0;
}