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

int n,t;
vi v;

void solve() {
	int i=0,j=0,ans=0,sum=0;
	for(;i<n;++i) {
		for(;j<n&&sum+v[j]<=t;++j) sum+=v[j];
		ans=max(ans,j-i);
		sum-=v[i];
	}

	cout<<ans<<'\n';
}


int main() {
	//freopen("sort.in", "r", stdin);
	//freopen("sort.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin>>n>>t;
	v.resize(n);
	for(auto &i: v) cin>>i;
	solve();

}
