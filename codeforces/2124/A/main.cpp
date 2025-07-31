#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define aml(x) begin(x), end(x)
#define raml(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define LSB(x) (x) & (-x)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int k,max_so_far,d,ans[2];

void solve() {
	ans[0]=ans[1]=max_so_far=INT_MIN;
	cin>>k;
	while(k--) {
		cin>>d;
		if (d < max_so_far) ans[0]=max_so_far,ans[1]=d;
		max_so_far = max(max_so_far, d);
	}

	if (ans[0] == INT_MIN) {
		cout<<"NO\n";
	} else {
		cout<<"YES\n2\n";
		cout<<ans[0]<<' '<<ans[1]<<'\n';
	}
}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) {
		solve();
	}
}
