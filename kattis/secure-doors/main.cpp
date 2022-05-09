#include <iostream>
#include <set>
#include <string>

std::string action, name;
int n;
std::set<std::string> s;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    while(n--) {
        std::cin >> action >> name;
        if(action == "entry")
            if (s.find(name) != s.end())
                std::cout << name << " entered (ANOMALY)\n"; 
            else {
                std::cout << name << " entered\n";
                s.insert(name);
            }
        else if(action == "exit") {
            auto it = s.find(name);
            if(it == s.end())
                std::cout << name << " exited (ANOMALY)\n";
            else {
                std::cout << name << " exited\n";
                s.erase(it);
            }
        }
    }

    return 0;
}