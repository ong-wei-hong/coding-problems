#include <iostream>
#include <string>

std::string s;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> s;
    std::cout << s[0];
    auto it = s.begin();
    while (it != s.end()) {
        if(*it == '-')
            std::cout << *(++it);
        ++it;
    }
    std::cout << '\n';
    return 0;
}