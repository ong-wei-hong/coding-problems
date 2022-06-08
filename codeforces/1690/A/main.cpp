#include <bits/stdc++.h>
using namespace std;

int t, n, q, r;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> n;
		q = (n-3)/3;
		r = (n-3)%3;
		if(r==2) cout << q+2 << ' ';
		else cout << q+1 << ' ';
		if(r>=1) cout << q+3 << ' ';
		else cout << q+2 << ' ';
		cout << q << '\n';
	}
}
