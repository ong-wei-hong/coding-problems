#include <iostream>
#include <string>

std::string s, t;

int main() {
    std::cin >> s >> t;
    if (s.length() >= t.length()) {
        std::cout << "go\n";
        return 0;
    }
    std::cout << "no\n";
    return 0;
}