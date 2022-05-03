#include <iostream>
#include <set>
#include <string>

int t, n;
std::string city;

int main() {
    std::cin >> t;
    for(int i{0}; i<t; ++i) {
        std::cin >> n;
        std::set<std::string> s {};
        for(int j{0}; j<n; ++j) {
            std::cin >> city;
            s.insert(city);
        }
        std::cout << s.size() << '\n';
    }

    return 0;
}