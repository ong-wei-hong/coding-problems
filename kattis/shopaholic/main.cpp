#include <algorithm>
#include <iostream>
#include <vector>

int n;
long long discount;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    std::vector<int> v(n);
    for(int& i: v)
        std::cin >> i;
    std::sort(v.begin(), v.end(), std::greater<int>());
    for(auto it {v.begin()+2}; it<v.end(); it+=3)
        discount += *it;
    std::cout << discount << '\n';
    return 0;
}