#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define LSB(x) (x) & (-x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <class T>
using Tree =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int N;
vector<int> v;
vector<vector<int>> children;

void solve(int i) {
	int mini=INT_MAX;
	for(auto j: children[i]) solve(j),mini=min(mini,v[j]);

	if(mini==INT_MAX) return;
	if(mini<=v[i]) v[i]=mini;
	else v[i]=(v[i]+mini)/2;
}

void solve() {
	cin>>N;
	v.resize(N+1);
	rep(i,1,N+1) cin>>v[i];
	children.assign(N+1,vi());
	rep(i,2,N+1) {
		int a;
		cin>>a;
		children[a].push_back(i);
	}

	for(auto i: children[1]) solve(i);
	ll ans=LLONG_MAX;
	for(auto i: children[1]) ans=min(ans,1LL*v[i]);
	ans+=v[1];
	cout<<ans<<'\n';
}

int main() {
	//freopen("split.in", "r", stdin);
	//freopen("split.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	int t;
	cin>>t;
	while(t--) solve();
}
