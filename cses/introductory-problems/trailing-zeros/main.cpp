#include <iostream>

int n, i, count;

int main() {
    std::cin >> n;
    while(n) {
        n /= 5;
        count += n;
    }
    std::cout << count << '\n';
}