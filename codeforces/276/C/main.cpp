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

constexpr int MAX_N=2e5;
int n,q;
vi diff,a;

void solve() {
	cin>>n>>q;
	a.resize(n),diff.resize(n+1);
	for(auto &i: a) cin>>i;
	while(q--) {
		int l,r;
		cin>>l>>r;
		--l,--r;
		++diff[l];
		--diff[r+1];
	}

	rep(i,1,n) diff[i]+=diff[i-1];
	diff.pop_back();
	ll ans=0;
	sort(rall(a)),sort(rall(diff));
	rep(i,0,n) ans+=1LL*a[i]*diff[i];
	cout<<ans<<'\n';
}

int main() {
	// freopen("lazy.in", "r", stdin);
	// freopen("lazy.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
