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
vi v;

void solve() {
	cin>>n;
	v.resize(n);
	for(auto &i: v) cin>>i;
	bool odd=0,even=0;
	for(auto i: v) odd=odd||(i&1),even=even||!(i&1);
	if(odd&&even) {
		cout<<"-1\n";
		return;
	}

	cout<<30+even<<'\n';
	for(int i=29;i>=0;--i) cout<<(1<<i)<<' ';
	if(even) cout<<'1';
	cout<<'\n';
}


int main() {
	//freopen("pairup.in", "r", stdin);
	//freopen("pairup.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();

}

