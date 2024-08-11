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

int n,q,m;
string s;
char c;

void solve() {
	cin>>m>>c;
	int ans=INT_MIN;
	for(int curr=0,i=0,j=0;j<n;++j) {
		curr+=(s[j]==c);
		if(j-i+1-curr<=m) ans=max(ans,j-i+1);
		else {
			while(i<j&&s[i]==c) --curr,++i;
			++i;
			ans=max(ans,j-i+1);
		}
	}

	cout<<ans<<'\n';
}

int main() {
	//freopen("herding.in", "r", stdin);
	//freopen("herding.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>s>>q;
	while(q--) solve();
}
	
