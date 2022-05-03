#include <iostream>

int main() {
    int x {}, y {}, n{};
    std::cin >> x >> y >> n;

    int i {0};
    while(++i <= n) {
        bool b1 {i % x == 0}, b2 {i % y == 0};
        if(b1 && b2) 
            std::cout << "FizzBuzz";
        else if(b1)
            std::cout << "Fizz";
        else if(b2)
            std::cout << "Buzz";
        else
            std::cout << i;

        std::cout << '\n';
    }

    return 0;
}