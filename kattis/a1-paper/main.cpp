#include <cmath>
#include <iomanip>
#include <iostream>

double result, l {std::pow(2.0, -0.75)}, w {std::pow(2.0, -1.25)}, temp, ls[31];
int n, x, papers[31], need {2};

int main() {
    std::cin >> n;
    for(int i{2}; i<=n; ++i) {
        std::cin >> x;
        papers[i] = std::min(need, x);
        need = std::max(0, need - x) * 2;
        ls[i] = l;
        temp = w;
        w = l / 2;
        l = temp;
    }
    if (need > 0) {
        std::cout << "impossible\n";
        return 0;
    }
    for(int i{n}; i>=2; --i) {
        papers[i] /= 2;
        papers[i-1] += papers[i];
        result += papers[i] * ls[i];
    }
    std::cout << std::setprecision(10) << result << '\n';
    return 0;
}