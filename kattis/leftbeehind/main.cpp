#include <iostream>

int x, y;

int main() {
    std::cin >> x >> y;
    while(x != 0 || y != 0) {
        if(x + y == 13)
            std::cout << "Never speak again.\n";
        else if(x > y)
            std::cout << "To the convention.\n";
        else if(y > x) 
            std::cout << "Left beehind.\n";
        else
            std::cout << "Undecided.\n";
        std::cin >> x >> y;
    }

    return 0;
}