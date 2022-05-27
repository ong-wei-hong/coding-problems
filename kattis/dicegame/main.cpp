#include <iostream>

int x, sum1, sum2;

int main() {
    for(int i{0}; i<4; ++i) {
        std::cin >> x;
        sum1 += x;
    }
    for(int i{0}; i<4; ++i) {
        std::cin >> x;
        sum2 += x;
    }

    if(sum1 == sum2)
        std::cout << "Tie\n";
    else
        std::cout << ((sum1 < sum2) ? "Emma\n" : "Gunnar\n");

    return 0;
}