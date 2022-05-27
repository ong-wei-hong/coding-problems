#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int n;

bool compare(const std::string& s1, const std::string& s2) {
    return s1.substr(0, std::min(static_cast<std::size_t>(2), s1.size())) < 
           s2.substr(0, std::min(static_cast<std::size_t>(2), s2.size()));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (std::cin >> n) {
        if (n == 0) return 0;
        std::vector<std::string> v(n);
        for(auto& i: v) std::cin >> i;
        std::stable_sort(v.begin(), v.end(), compare);
        for(const auto& i: v) std::cout << i << '\n';
        std::cout << '\n';
    }
}