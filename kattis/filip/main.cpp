#include <iostream>
#include <string>

std::string s;
int v[2];

int main() {
    for(auto& i: v) {
        std::cin >> s;
        for(auto it {s.rbegin()}; it != s.rend(); ++it)
            i = i * 10 + (*it - '0');
    }
    std::cout << std::max(v[0], v[1]) << '\n';
    return 0;
}