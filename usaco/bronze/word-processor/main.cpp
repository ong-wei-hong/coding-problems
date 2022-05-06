#include <iostream>
#include <string>

int n, k, count;
std::string s;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    std::cin >> n >> k;
    
    std::cin >> s;
    count += s.size();
    std::cout << s;

    for(int i{1}; i<n; ++i) {
        std::cin >> s;
        count += s.size();
        if(count > k) {
            std::cout << '\n' << s;
            count = s.size();
        } else 
            std::cout << ' ' << s;
    }
    
    return 0;
}