#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> m;
std::string v, k, l;
int i;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while(std::getline(std::cin, l) && l != "") {
        i = l.find(' ');
        v = l.substr(0, i);
        k = l.substr(i+1, l.size()-1);
        m.insert({k, v});
    }

    while (std::cin >> k) {
        auto it = m.find(k);
        if (it == m.end())
            std::cout << "eh\n";
        else
            std::cout << it->second << '\n';
    }

    return 0;
}