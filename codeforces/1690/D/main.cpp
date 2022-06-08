#include <bits/stdc++.h>
using namespace std;

char c;
int t, n, k, a[200002], m;

int main() {
	cin >> t;
	while(t--) {
		cin >> n >> k;
		a[1] = 0;
		for(int i=1; i<=n; ++i) {
			cin >> c;
			if(c == 'W')
				a[i] += 1;
			a[i+1] = a[i];
		}
		m=k;
		for(int i=k; i<=n; ++i) m = min(m, a[i] - a[i-k]);
		cout << m << '\n';
	}
	return 0;
}

