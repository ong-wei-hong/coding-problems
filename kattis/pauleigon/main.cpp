#include <iostream>

int n, p, q;

int main() {
    std::cin >> n >> p >> q;
    if(((p + q) / n) % 2) 
        std::cout << "opponent\n";
    else
        std::cout << "paul\n";

    return 0;
}