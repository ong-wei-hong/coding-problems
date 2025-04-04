#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define LSB(x) (x) & (-x)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<ll> a,suffix;

void solve() {
	cin>>n;
	a.resize(n);
	suffix.assign(n,0);
	rep(i,0,n) {
		cin>>a[i];
		if (a[i] < 0) suffix[i] -= a[i];
	}
	for(int i=n-2;i>=0;--i) suffix[i] += suffix[i+1];

	ll res=0,prefix=0;
	rep(i,0,n) {
		prefix += max(0LL,a[i]);
		res = max(res, prefix + suffix[i]);
	}
	cout<<res<<'\n';
}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
