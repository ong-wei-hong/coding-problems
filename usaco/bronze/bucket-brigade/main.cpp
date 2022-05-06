#include <iostream>

int b_x, b_y, l_x, l_y, r_x, r_y, ans;
char ch;

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    for(int i{0}; i<10; ++i)
        for(int j{0}; j<10; ++j) {
            std::cin >> ch;
            switch(ch) {
                case 'B': 
                    b_x = j;
                    b_y = i;
                    break;
                case 'R':
                    r_x = j;
                    r_y = i;
                    break;
                case 'L':
                    l_x = j;
                    l_y = i;
                    break;
            }
        }

    ans = std::abs(b_x - l_x) + std::abs(b_y - l_y) - 1;
    if((b_x == l_x && b_x == r_x && ((l_y - r_y > 0) == (r_y - b_y > 0))) ||
       (b_y == l_y && b_y == r_y && ((l_x - r_x > 0) == (r_x - b_x > 0))))
        ans += 2;

    std::cout << ans;
    return 0;
}