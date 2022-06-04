#include <iostream>
#include <string>

std::string s;
int stars, rank{25}, win_streak;

int max_stars(int rank) {
	if(rank <= 10) return 5;
	if(rank <= 15) return 4;
	if(rank <= 20) return 3;
	return 2;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> s;
	
	for(const auto& c: s)
		if(c == 'L') {
			win_streak = 0;
			if(rank <= 20) {
				if(stars == 0) {
					if (rank == 20) continue;
					++rank;
					stars = max_stars(rank);
				}
				--stars;
			}
		} else if(c == 'W') {
			++win_streak;
			++stars;
			if(win_streak >= 3 && rank >= 6) ++stars;
			while(stars > max_stars(rank)) {
				stars = stars-max_stars(rank);
				--rank;
			}

			if(rank == 0) {
				std::cout << "Legend\n";
				return 0;
			}
		}
	std::cout << rank << '\n';
	return 0;
}


