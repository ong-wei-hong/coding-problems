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
vector<ll> a,b,d;

void solve() {
	cin>>n;
	a.resize(2*n);
	for(auto &i: a) cin>>i;
	sort(rall(a));

	b.resize(n);
	rep(i,0,n)
		if(a[2*i]!=a[2*i+1]) {
			cout<<"NO\n";
			return;
		} else b[i]=a[2*i];

	d.resize(n);
	rep(i,1,n)
		if(b[i]==b[i-1]||(b[i-1]-b[i])%(2*(n-i))) {
			cout<<"NO\n";
			return;
		} else d[i]=(b[i-1]-b[i])/(2*(n-i));

	rep(i,1,n) b[n-1]-=2*i*d[i];

	if(b[n-1]<=0||b[n-1]%(2*n)) cout<<"NO\n";
	else cout<<"YES\n";

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
