#include <iostream>
#include <string>

int characters[26];
std::string s;
int a, odd_index, i, j;
bool odd;
char c;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> s;

    a = static_cast<int>('A');
    for(auto c: s)
        ++characters[static_cast<int>(c) - a];

    odd_index = -1;
    for(i=0; i<26; ++i)
        if(characters[i] % 2) {
            if(odd_index != -1) {
                std::cout << "NO SOLUTION\n";
                return 0;
            }
            odd_index = i;
        } else 
            characters[i] /= 2;

    for(i=0; i<26; ++i) {
        if(odd_index == i) 
            continue;
        c = static_cast<char>(a+i);
        for(j=0; j<characters[i]; ++j)
            std::cout << c;
    }

    if(odd_index != -1) {
        c = static_cast<char>(a+odd_index);
        for(j=0; j<characters[odd_index]; ++j)
            std::cout << c;
    }

    for(i=25; i>=0; --i) {
        if(odd_index == i)
            continue;
        c = static_cast<char>(a+i);
        for(j=0; j<characters[i]; ++j)
            std::cout << c;
    }

    std::cout << '\n';
    return 0;
}