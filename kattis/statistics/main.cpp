#include <iostream>
#include <string>
#include <sstream>

int n, j, min, max, x;
std::string line;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	for(int i=1; std::cin >> n; ++i) {
		std::cin >> x;
		min = max = x;
		for(int j=1; j<n; ++j) {
			std::cin >> x;
			min = std::min(min, x);
			max = std::max(max, x);
		}
		std::cout << "Case " << i << ": " << min << ' ' << max << ' ' << (max - min) << '\n';
	}
}
