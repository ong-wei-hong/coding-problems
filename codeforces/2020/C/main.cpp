#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define LSB(x) (x) & (-x)
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll a,b,c,d;

ll get_bit(ll &n, int i) {
	return (n >> i) & 1LL;
}

void solve() {
	a=0;
	cin>>b>>c>>d;

	rep(i,0,62) {
		ll b_bit=get_bit(b,i),c_bit=get_bit(c,i),d_bit=get_bit(d,i);
		if((b_bit&&!c_bit&&!d_bit)||(!b_bit&&c_bit&&d_bit)) {
			cout<<"-1\n";
			return;
		}

		if(!b_bit) a = a | (d_bit<<i);
		else a = a | ((1LL-d_bit)<<i);

	}

	cout<<a<<'\n';
}

int main() {
//	freopen("loan.in", "r", stdin);
//	freopen("loan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
