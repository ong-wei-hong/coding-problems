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

int n,k;

void solve() {
	cin>>n>>k;

	if(k==0) {
		cout<<"0\n";
		return;
	}

	if(k<=n) {
		cout<<"1\n";
		return;
	}

	k-=n;
	int i=1,ans=1;
	while(1) {
		k-=(n-i);
		++ans;
		if(k<=0) {
			cout<<ans<<'\n';
			return;
		}

		k-=(n-i);
		++ans;
		if(k<=0) {
			cout<<ans<<'\n';
			return;
		}
		++i;
	}
}

int main() {
	//freopen("lifeguards.in", "r", stdin);
	//freopen("lifeguards.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
