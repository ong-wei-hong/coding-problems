#include <iostream>

int n, ans, xs[100000], max_from_left[100000], min_from_right[100000];

int main() {
    std::cin >> n;
    for(int i{0}; i<n; ++i)
        std::cin >> xs[i];

    max_from_left[0] = xs[0];
    for(int i{1}; i<n; ++i)
        max_from_left[i] = std::max(max_from_left[i-1], xs[i]);

    min_from_right[n-1] = xs[n-1];
    for(int i{n-2}; i>=0; --i)
        min_from_right[i] = std::min(min_from_right[i+1], xs[i]);

    ans += (xs[0] <= min_from_right[0]) + (xs[n-1] >= max_from_left[n-1]);
    for(int i{1}; i<n-1; ++i)
        ans += (xs[i] >= max_from_left[i-1] && xs[i] <= min_from_right[i+1]);

    std::cout << ans;
    return 0;
}