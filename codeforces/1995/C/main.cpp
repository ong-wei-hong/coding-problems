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
vector<ll> a;

void solve() {
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;

	ll ans=0,curr=0;
	rep(i,0,n-1) {
		if(a[i]!=1&&a[i+1]==1) {
			cout<<"-1\n";
			return;
		}

		ll x=a[i],y=a[i+1],new_curr=0;
		while(curr>0&&x<y) --curr,x=x*x;
		while(y<x) y=y*y,++new_curr;
		new_curr+=curr;
		ans+=new_curr;
		curr=new_curr;
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
