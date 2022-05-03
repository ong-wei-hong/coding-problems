#include <iostream>

int prev, curr, n;
long long s;

int main() {
    std::cin >> n >> prev;
    for(int i{1}; i<n; ++i) {
        std::cin >> curr;
        if(curr < prev)
            s += (prev - curr);
        else
            prev = curr;
    }
    std::cout << s;
}