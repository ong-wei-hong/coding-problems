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

int k,n,c;
vector<vector<int>> prefix;
vector<bool> dp;
string s;

void solve() {
	cin>>n>>c>>k>>s;
	prefix.assign(n+1,vi(c,0));
	rep(i,0,n) {
		rep(j,0,c) prefix[i+1][j]=prefix[i][j];
		++prefix[i+1][s[i]-'A'];
	}

	dp.assign((1<<c),false);
	rep(i,0,n-k+1) {
		int bitmask=0;
		rep(j,0,c) if(prefix[i+k][j]>prefix[i][j]) bitmask|=(1<<j);
		dp[((1<<c)-1)^bitmask]=true;
	}
	dp[((1<<c)-1)^(1<<(s.back()-'A'))]=true;

	int ans=INT_MAX;
	for(int bitmask=(1<<c)-1;bitmask>=0;--bitmask) {
		rep(i,0,c) dp[bitmask]=dp[bitmask]||dp[bitmask|(1<<i)];
		if(!dp[bitmask]) ans=min(ans,__builtin_popcount(bitmask));
	}

	cout<<ans<<'\n';
}

int main() {
	//freopen("lifeguards.in", "r", stdin);
	//freopen("lifeguards.out", "w", stdout);
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
