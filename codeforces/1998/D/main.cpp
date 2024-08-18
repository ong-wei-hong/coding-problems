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

// d_v < v - S - 1
// d_v - v < S - 1

int n,m,u,v;
vector<vi> g,rg;
vi mini;

void solve() {
	cin>>n>>m;
	g.assign(n,vi());
	rg.assign(n,vi());

	while(m--) {
		cin>>u>>v;
		--u,--v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}

	rep(i,0,n-1) g[i].push_back(i+1);
	rep(i,1,n) rg[i].push_back(i-1);

	mini.assign(n,INT_MAX);
	mini[0]=0;
	rep(i,0,n) {
		for(auto j: g[i]) mini[j]=min(mini[j],mini[i]+1);
	}

	multiset<int> ms;
	vector<vector<int>> to_remove(n);
	string ans = string(n-1,'1');
	// for Elsie to win
	// t_v < v - i
	// i < v - t_v
	for(int i=n-1;i>=0;--i) {
		for(auto j: rg[i]) {
			ms.insert(i-mini[j]-1);
			to_remove[j].push_back(i-mini[j]-1);
		}
		for(auto j: to_remove[i]) ms.erase(ms.find(j));

		if(i!=n-1) {
			int k= ms.empty() ? -1 : *ms.rbegin();
			if(i < k) ans[i]='0';
		}
	}

	cout<<ans<<'\n';
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

