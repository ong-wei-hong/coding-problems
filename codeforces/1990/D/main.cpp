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

int n;
vi a;

void solve() {
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;
	int ans=0;
	bool b1=0,b2=0;

	for(auto i: a) {
		if(!(b1||b2)) {
			if(i==0) continue;
			++ans;
			if(i<=2) b1=1;
		} else if(b1) {
			b1=0;
			if(i<=2) continue;
			++ans;
			if(i<=4) b2=1;
		} else {
			b2=0;
			if(i==0) continue;
			++ans;
			if(i<=4) b1=1;
		}
	}

	cout<<ans<<'\n';
}

int main() {
	//freopen("art.in", "r", stdin);
	//freopen("art.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
