#include <iostream>

int x, t, ix;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--) {
        std::cin >> x;
        ix = x & (-x);
        while (!((ix & x) && (ix ^ x))) ++ix;
        std::cout << ix << '\n';
    }
    return 0;
}