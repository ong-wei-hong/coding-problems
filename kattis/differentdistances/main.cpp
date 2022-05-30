#include <iostream>
#include <cmath>
#include <iomanip>

double x1,y3,x2,y2,p;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::setprecision(10);
    while(true) {
        std::cin >> x1;
        if(x1 == 0) return 0;
        std::cin >> y3 >> x2 >> y2 >> p;
        std::cout << std::pow(std::pow(std::abs(x1-x2), p) + std::pow(std::abs(y3-y2), p), 1.0/p) << '\n';
    }
    return 0;
}