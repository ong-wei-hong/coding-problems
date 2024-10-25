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
vi a,b;
vector<vector<pii>> al;
vector<ll> sssp;

void solve() {
	cin>>n;
	a.resize(n),b.resize(n);
	for(auto &i: a) cin>>i;
	for(auto &i: b) cin>>i,--i;

	al.assign(n,vector<pii>());
	sssp.assign(n,LLONG_MAX);

	rep(i,1,n) al[i].push_back({0,i-1});
	rep(i,0,n) al[i].push_back({a[i],b[i]});

	std::priority_queue<pair<ll,int>> pq;
	pq.push({0LL,0});
	sssp[0] = 0LL;

	while(!pq.empty()) {
		auto [cost, node] = pq.top();
		cost = -cost;
		pq.pop();
		if(sssp[node] != cost) continue;

		for(const auto &[cst,nxt]: al[node]) {
			ll nxt_cst = cost + cst;
			if (nxt_cst < sssp[nxt]) pq.push({-nxt_cst,nxt}), sssp[nxt] = nxt_cst;
		}
	}

//	cout<<"al: \n";
//	for(auto v: al) {
//		for(auto p: v) cout<<p.fi<<','<<p.se<<' ';
//		cout<<'\n';
//	}
//
//	cout<<"sssp: ";
//	for(auto i: sssp) cout<<i<<' ';
//	cout<<'\n';

	ll sum=0,ans=0;
	rep(i,0,n) {
		sum += a[i];
		if (sssp[i] != LLONG_MAX) ans = max(ans, sum - sssp[i]);
	}

	cout<<ans<<'\n';
}

int main() {
//	freopen("fenceplan.in", "r", stdin);
//	freopen("fenceplan.out", "w", stdout);
//	cin.tie(0)->sync_with_stdio(0);
//	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	rep(_,0,t) solve();
}
