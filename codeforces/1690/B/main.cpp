#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)

int t, n, a[50000], b[50000];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> n;
		forn(i, n) cin >> a[i];
		forn(i, n) cin >> b[i];
		int d = 1e9;
		forn(i, n) if(b[i] != 0) d = min(d, a[i]-b[i]);
		if (d < 0) {
			cout << "NO\n";
			continue;
		}
		bool v=1;
		forn(i, n)
			if((a[i]-b[i]>d)||(b[i]!=0 && a[i]-b[i]<d)) {
				cout << "NO\n";
				v=0;
				break;
			}
		if (v)
		cout << "YES\n";
	}
	return 0;
}
		
