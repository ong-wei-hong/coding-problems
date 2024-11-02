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

int n,color_to_cnt[2],u,v;
vector<vi> al;

void dfs(int node, int color, int prev) {
	++color_to_cnt[color];
	color=1-color;

	for(auto i: al[node]) if(i != prev) dfs(i,color,node);
}

void solve() {
	cin>>n;
	al.resize(n);
	rep(_,0,n-1) {
		cin>>u>>v;
		--u,--v;
		al[u].push_back(v);
		al[v].push_back(u);
	}

	dfs(0,0,-1);

	cout<<1LL*color_to_cnt[0]*color_to_cnt[1] - (n-1)<<'\n';
	
}


int main() {
//	freopen("fenceplan.in", "r", stdin);
//	freopen("fenceplan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
