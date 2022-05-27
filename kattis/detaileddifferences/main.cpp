#include <iostream>
#include <string>

int n;
std::string s1, s2;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    while(n--) {
        std::cin >> s1 >> s2;
        std::cout << s1 << '\n' << s2 << '\n';
        auto it1 = s1.begin();
        auto it2 = s2.begin();
        while(it1 != s1.end())
            std::cout << (*(it1++) == *(it2++) ? '.' : '*');
        std::cout << "\n\n";
    }
    return 0;
}