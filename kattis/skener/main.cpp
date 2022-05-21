#include <iostream>
#include <string>

int r, c, zr, zc;
std::string s;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> r >> c >> zr >> zc;
    while (r--) {
        std::cin >> s;
        for(int i{0}; i<zr; ++i) {
            for(auto& c: s)
                for(int j{0}; j<zc; ++j)
                    std::cout << c;
            std::cout << '\n';
        }
    }
    return 0;
}