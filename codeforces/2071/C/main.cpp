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

int n,st,en,u,v;
vector<vi> al,depth_to_v;

void dfs(int curr, int prev, int depth) {
	depth_to_v[depth].push_back(curr);
	for(auto v: al[curr]) if(v!=prev) {
		dfs(v,curr,depth+1);
	}
}

void solve() {
	cin>>n>>st>>en;
	al.assign(n+1,vi());
	rep(_,0,n-1) {
		cin>>u>>v;
		al[u].push_back(v);
		al[v].push_back(u);
	}
	depth_to_v.assign(n,vi());
	dfs(en,0,0);
	for(int i=n-1;i>=0;--i) for(auto v: depth_to_v[i]) cout<<v<<' ';
	cout<<'\n';
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
