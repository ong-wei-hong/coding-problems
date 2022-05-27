#include <iostream>
#include <set>
#include <string>

int i;
std::string s[101];
std::set<std::string> set;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while(std::cin >> s[i++]);

	for(int j{0}; j<i-1; ++j)
		for(int k{0}; k<i-1; ++k)
			if(j != k)
				set.insert(s[j] + s[k]);

	for(const auto& s: set)
		std::cout << s << '\n';

	return 0;
}
