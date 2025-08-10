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

int n,k;
vector<pii> v;

void solve() {
	cin>>n>>k;
	v.resize(n);
	for(auto &it: v) cin>>it.fi;
	ll sum_of_differences = 0;
	for(auto &it: v) {
		cin>>it.se;
		if(it.fi > it.se) swap(it.fi, it.se);
		sum_of_differences += it.se - it.fi;
	}

	sort(all(v));
	int min_diff = INT_MAX,highest_so_far=v[0].se;
	rep(i,1,n) {
		min_diff = min(min_diff, v[i].fi - highest_so_far);
		highest_so_far = max(highest_so_far, v[i].se);
	}

	sum_of_differences += 2 * max(0, min_diff);
	cout<<sum_of_differences<<'\n';
}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) {
		solve();
	}
}
