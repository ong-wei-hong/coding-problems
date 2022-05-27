#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <map>

int n;
std::string s, t, name;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    while(n != 0) {
        std::map<std::string, std::set<std::string>> map;
        for(int i=0; i<n; ++i) {
            std::cin >> name;
            std::getline(std::cin, s);
            std::stringstream ss (s);
            while(ss >> t) {
                auto it {map.find(t)};
                if(it == map.end()) {
                    std::set<std::string> s;
                    s.insert(name);
                    map[t] = s;
                } else it->second.insert(name);
            }
        }
        for(auto it {map.begin()}; it != map.end(); ++it) {
            std::cout << it->first;
            for(const auto& s: it->second)
                std::cout << ' ' << s;
            std::cout << '\n';
        }
        std::cin >> n;
    }
}