#include <iostream>
#include <string>

bool swap, increasing;
std::string s1, s2;
int n;

int main() {
    std::cin >> n >> s1 >> s2;

    increasing = s2 > s1;

    for(int i{2}; i<n; ++i) {
        if(swap) {
            std::cin >> s2;
            if(increasing != (s2 > s1)) {
                std::cout << "NEITHER\n";
                return 0;
            }
        } else {
            std::cin >> s1;
            if(increasing != (s1 > s2)) {
                std::cout << "NEITHER\n";
                return 0;
            }
        }
        swap = !swap;
    }

    std::cout << (increasing ? "INCREASING\n" : "DECREASING\n");
    return 0;
}