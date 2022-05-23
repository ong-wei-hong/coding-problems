#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

int n, x;
std::string s, t;
std::string cups[1000];

bool is_number(const std::string& s) {
    for(const auto& c: s)
        if(!std::isdigit(c))
            return false;
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i{0}; i<n; ++i) {
        std::cin >> s >> t;
        if (is_number(s)) cups[std::stoi(s) / 2].swap(t);
        else cups[std::stoi(t)].swap(s);
    }
        
    for (const auto& i: cups)
        if(i.size()) std::cout << i << '\n';

    return 0;
}
