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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<pii> a;

void solve() {
	cin>>n;
	a.resize(n);
	for(auto &it: a) cin>>it.fi>>it.se;

	sort(all(a),[](pii a, pii b) {
		if(max(a.fi,a.se)==max(b.fi,b.se)) 
			return min(a.fi,a.se) < min(b.fi,b.se);
		return max(a.fi,a.se) < max(b.fi,b.se);
	});

	for(auto &it: a) cout<<it.fi<<' '<<it.se<<' ';
	cout<<'\n';

}

int main() {
//	freopen("fenceplan.in", "r", stdin);
//	freopen("fenceplan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
