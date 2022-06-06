#include <cmath>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES

int i;

int main() {
	std::cin >> i;
	std::cout << std::setprecision(10) << std::fixed << i * i * M_PI << '\n' << 2 * i * i << '\n';
	return 0;
}
