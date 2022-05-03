#include <iostream>

int sum, difference, d, dwarfs[9];
bool set[100];

int main() {
    for(int& i: dwarfs) {
        std::cin >> i;
        sum += i;
        set[i] = true;
    }

    difference = sum - 100; // find 2 numbers that add up to difference
    for(int& i: dwarfs) {
        d = difference - i;
        if(d != i && set[d]) { // d found
            for(int& j: dwarfs) {
                if (j != i && j != d) 
                    std::cout << j << '\n';
            }
            return 0;
        }
    }
}