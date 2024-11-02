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
vector<ll> a;
map<ll,vector<int>> m;
set<ll> visited;

ll dfs(ll l) {
	if(visited.count(l)) return l;
	visited.insert(l);

	auto it=m.find(l);
	if(it==m.end()) return l;

	ll res=l;
	for(auto i: it->se) res = max(res, dfs(l+i));
	return res;
}

void solve() {
	cin>>n;
	a.resize(n);
	m.clear();
	visited.clear();

	for(auto &i: a) cin>>i;

	rep(i,1,n)
		m[a[i]+i].push_back(i);

	cout<<dfs(n)<<'\n';
}

int main() {
//	freopen("fenceplan.in", "r", stdin);
//	freopen("fenceplan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	rep(_,0,t) solve();
}
