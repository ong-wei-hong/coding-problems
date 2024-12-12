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

int n,m,v; 
vector<ll> a,sat_cnt_prefix,sat_cnt_to_suffix_pos,prefix;

void solve() {
	cin>>n>>m>>v;
	a.resize(n);
	sat_cnt_prefix.resize(n);
	sat_cnt_to_suffix_pos.assign(n+1,-1);
	prefix.resize(n);
	for(auto &i: a) cin>>i;

	{
		int sum=0,cnt=0;
		rep(i,0,n) {
			sum += a[i];
			if (sum >= v) ++cnt,sum=0;
			sat_cnt_prefix[i] = cnt;
		}
	}

	{
		int sum=0,cnt=0;
		sat_cnt_to_suffix_pos[0] = n;
		for(int i=n-1;i>=0;--i) {
			sum += a[i];
			if (sum >= v) sat_cnt_to_suffix_pos[++cnt] = i,sum = 0;
		}
	}

	prefix[0] = a[0];
	rep(i,1,n) prefix[i] = prefix[i-1] + a[i];

	if (sat_cnt_prefix.back() < m) {
		cout<<"-1\n";
		return;
	}

	ll ans=0LL;
	{
		int idx = sat_cnt_to_suffix_pos[m];
		if (idx != -1 && idx != 0) ans = prefix[idx - 1];
	}

	rep(i,1,n) {
		int cnt_sat = min((int)sat_cnt_prefix[i-1],m);
		if (cnt_sat != 0) {
			int idx = sat_cnt_to_suffix_pos[m - cnt_sat];
			if (idx != -1 && idx-1 >= i-1) ans = max(ans, prefix[idx - 1] - prefix[i-1]);
		}
	}

	cout<<ans<<'\n';

}

int main() {
//	freopen("revegetate.in", "r", stdin);
//	freopen("revegetate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
