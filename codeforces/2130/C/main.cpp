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
vector<pii> v;
vector<bool> keep;

void solve() {
	cin>>n;
	v.resize(n);
	for(auto &p: v) cin>>p.fi>>p.se;
	keep.assign(n,true);
	rep(i,0,n) rep(j,0,n) if(i!=j && v[i].fi <= v[j].fi && v[i].se >= v[j].se) keep[j] = false;
	int cnt=0;
	for(auto b: keep) cnt += b;

	cout<<cnt<<'\n';
	rep(i,0,n) if(keep[i]) cout<<i+1<<' ';
	cout<<'\n';
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
