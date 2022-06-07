#include <bits/stdc++.h>

using namespace std;

int t, n;
char c;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while(t--) {
		cin >> n;
		n = 2*n+1;
		c=0;
		while(n--) {
			cin >> s;
			for(const auto& d: s) c ^= d;
		}
		cout << c <<'\n';
	}
}
