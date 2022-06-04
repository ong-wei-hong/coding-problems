#include <iostream>

bool b[100001];
int n, m, gs[100000];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i=0; i<m; ++i) { 
        std::cin >> gs[i];
        b[gs[i]] = true;
    }
    int i {1}, j{0};
    while (i <= n && j < m) {
        while(b[i]) ++i;
        if (i < gs[j])
            std::cout << i++ << '\n';
        else
            std::cout << gs[j++] << '\n';
    }

    while(i <= n) std::cout << i++ << '\n';
    while(j < m) std::cout << gs[j++] << '\n';
    return 0;
}
