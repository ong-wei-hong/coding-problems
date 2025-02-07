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
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr ll MOD = 998244353;
int n;
vector<ll> v,dp_hon,dp_lie;

void solve() {
	cin>>n;
	v.resize(n);
	dp_hon.resize(n);
	dp_lie.resize(n);

	for(auto &i: v) cin>>i;
	dp_hon[0] = (v[0] == 0);
	dp_lie[0] = 1;

	rep(i,1,n) {
		dp_hon[i] = dp_lie[i] = 0;

		dp_lie[i] = dp_hon[i-1];
		if(v[i] == v[i-1]) dp_hon[i] = dp_hon[i-1];
		
		if(i == 1) {
			if(v[i]==1) dp_hon[i] = (dp_hon[i] + 1) % MOD;
		} else {
			if(v[i] == v[i-2]+1) dp_hon[i] = (dp_hon[i] + dp_hon[i-2]) % MOD;
		}
	}

	cout<<(dp_hon.back() + dp_lie.back()) % MOD<<'\n';
}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
