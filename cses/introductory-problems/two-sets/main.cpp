#include <iostream>
int n;

int main() {
    std::cin >> n;
    if(n & 1) {
        if((n+1) % 4) {
            std::cout << "NO\n";
            return 0;
        }
        std::cout << "YES\n";
        int i {1};
        int j {(n-3)/2};

        std::cout << j + 1 << '\n';
        while(i<=j/2) {
            std::cout << i << ' ' << n-i << ' ';
            ++i;
        }
        std::cout << n << '\n';

        std::cout << j + 2 << '\n';
        while(i<(n+1)/2) {
            std::cout << i << ' ' << n-i << ' ';
            ++i;
        }
    } else {
        if(n % 4) {
            std::cout << "NO\n";
            return 0;
        }
        std::cout << "YES\n" << n/2 << '\n';
        int i{1};
        while(i<=n/4) {
            std::cout << i << ' ' << n+1-i << ' ';
            ++i;
        }
        std::cout << '\n' << n/2 << '\n';
        while(i<=n/2) {
            std::cout << i << ' ' << n+1-i << ' ';
            ++i;
        }
    }

    return 0;
}