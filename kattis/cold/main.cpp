#include <iostream>

int main() {
    int count {0};

    int n {};
    std::cin >> n;

    for(int i {0}; i<n; ++i) {
        int t {};
        std::cin >> t;
        count += (t < 0);
    }

    std::cout << count << '\n';
    return 0;
}