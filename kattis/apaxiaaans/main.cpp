#include <iostream>

char prev, curr;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> prev;
	std::cout << prev;

	while(std::cin >> curr) 
		if (curr != prev) {
			std::cout << curr;
			prev = curr;
		}

	std::cout << '\n';
	return 0;
}
