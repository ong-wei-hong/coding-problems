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
vector<pair<ll,ll>> v;

void solve() {
	cin>>n;
	v.resize(n+2);
	for(auto &p: v) cin>>p.fi>>p.se;
	ll mini=LLONG_MAX;
	rep(i,0,n) mini=min(mini,(v[i].fi-v[n+1].fi)*(v[i].fi-v[n+1].fi)+(v[i].se-v[n+1].se)*(v[i].se-v[n+1].se));
	ll d=(v[n].fi-v[n+1].fi)*(v[n].fi-v[n+1].fi)+(v[n].se-v[n+1].se)*(v[n].se-v[n+1].se);
//	cout<<d<<' '<<mini<<' ';
	if(d<mini) cout<<"Yes\n";
	else cout<<"No\n";
}

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}

