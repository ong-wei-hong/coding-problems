#include <bits/stdc++.h>
using namespace std;

int t, n, s[200001], f[200001], e;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i=0; i<n; ++i) cin >> s[i];
		for(int i=0; i<n; ++i) cin >> f[i];
		e=0;
		for(int i=0; i<n; ++i) {
			cout << f[i] - max(e, s[i]) << ' ';
			e = max(e, f[i]);
		}
		cout << '\n';
	}
	return 0;
}
