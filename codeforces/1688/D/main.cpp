#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, k;
ll a[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1; i<=n; ++i) cin >> a[i], a[i] += a[i-1];
		if(k >= n) cout << a[n] + (k-1ll+k-n)*n/2 << '\n';
		else {
			ll m = a[k];
			for(int i=k+1; i<=n; ++i) m = max(m, a[i] - a[i-k]);
			cout << m + (k-1ll)*k/2 << '\n';
		}
	}
	return 0;
}
		
