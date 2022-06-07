#include <bits/stdc++.h>

using namespace std;

int t, n, a[200000], i, j;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while(t--) {
		cin >> n;
		for(i=0; i<n; ++i) {
			cin >> a[i];
			a[i] = __builtin_ffs(a[i])-1;
		}
		j = max(*min_element(a, a+n)-1, 0);
		for(i=0; i<n; ++i) j += (a[i]>0);
		cout << j << '\n';
	}
	return 0;
}
