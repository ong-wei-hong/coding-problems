#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int n;

int char_to_int(const char c) {
    return c - '0';
}

int get_hour(const std::string& s) {
    if (s.size() == 9) return char_to_int(s[0]);
    return char_to_int(s[0]) * 10 + char_to_int(s[1]);
}

int get_minute(const std::string& s) {
    if (s.size() == 9) return char_to_int(s[2]) * 10 + char_to_int(s[3]);
    return char_to_int(s[3]) * 10 + char_to_int(s[4]);
}

bool compare(const std::string& s1, const std::string& s2) {
    char s1a {s1[s1.size() - 4]}, s2a {s2[s2.size() - 4]};
    if (s1a != s2a) return s1a < s2a;
    int s1h {get_hour(s1)}, s2h {get_hour(s2)};
    if (s1h != s2h) return s1h % 12 < s2h % 12;
    return get_minute(s1) < get_minute(s2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (true) {
        std::cin >> n;
        if (n == 0) return 0;
        std::vector<std::string> v(n);
        std::cin.ignore(256, '\n');
        for(std::string& s: v) std::getline(std::cin, s);
        std::sort(v.begin(), v.end(), compare);
        for(std::string& s: v) std::cout << s << '\n';
        std::cout << '\n';
    }
}