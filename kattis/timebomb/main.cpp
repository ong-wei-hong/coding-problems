#include <iostream>
#include <string>

std::string ss[5];
int length, ans;

const std::string numbers[10] { "**** ** ** ****", "  *  *  *  *  *", "***  *****  ***", 
				"***  ****  ****", "* ** ****  *  *", "****  ***  ****",
				"****  **** ****", "***  *  *  *  *", "**** ***** ****",
				"**** ****  ****" };

bool compare(int start, const std::string& s) {
	int i=0;
	for(int j=0; j<5; ++j)
		for(int k=0; k<3; ++k)
			if(ss[j][start+k] != s[i++])
				return false;
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	for(int i=0; i<5; ++i) std::getline(std::cin, ss[i]);
	
	for(int i=0; i<ss[0].length(); i+=4) {
		bool invalid {true};
		for(int j=0; j<10; ++j)
			if(compare(i, numbers[j])) {
				invalid = false;
				ans = ans * 10 + j;
				break;
			}
		if (invalid) {
			std::cout << "BOOM!!\n";
			return 0;
		}
	}
	if(ans % 6 == 0)
		std::cout << "BEER!!\n";
	else std::cout << "BOOM!!\n";
	return 0;
}
