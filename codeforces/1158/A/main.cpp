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

int n,m;
vector<ll> girls,boys;

void solve() {
	cin>>n>>m;
	boys.resize(n);
	for(auto &i: boys) cin>>i;
	sort(rall(boys));

	girls.resize(m);
	for(auto &i: girls) cin>>i;
	sort(all(girls));
	
	if(boys[0]>girls[0]) {
		cout<<"-1\n";
		return;
	}

	ll ans=0;
	rep(i,1,m) ans+=girls[i];
	if(girls[0]==boys[0]) ans+=girls[0]+boys[1]*m;
	else ans+=boys[0]+girls[0]+boys[1]*(m-1);

	rep(i,2,n) ans+=boys[i]*m;

	cout<<ans<<'\n';
}

int main() {
//	freopen("cardgame.in", "r", stdin);
//	freopen("cardgame.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
