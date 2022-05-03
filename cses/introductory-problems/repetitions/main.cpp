#include <iostream>
#include <string>

std::string s;
int x, curr {1};

int main() {
    std::cin >> s;
    for(int i{1}; i<s.size(); ++i) {
        if(s[i] == s[i-1])
            ++curr;
        else {
            x = std::max(curr, x);
            curr = 1;
        }
    }
    x = std::max(curr, x);
    std::cout << x << '\n';

    return 0;
}