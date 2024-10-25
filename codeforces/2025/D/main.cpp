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

int n,m;
vi dp,rs;

void solve() {
	cin>>n>>m;
	rs.resize(n);
	for(auto &i: rs) cin>>i;
	rs.push_back(0);

	vi strength_checks_prefix(m+4),intelligence_checks_prefix(m+4);

	int i = 0;
	while(i<n && rs[i] != 0) ++i;

	for(;i<n+1;++i) {
		int r = rs[i];
		if (r < 0) strength_checks_prefix[-r] += 1;
		else if(r > 0) intelligence_checks_prefix[r] += 1;
		else if(r == 0) {
			rep(i,1,m+1) strength_checks_prefix[i] += strength_checks_prefix[i-1];
			rep(i,1,m+1) intelligence_checks_prefix[i] += intelligence_checks_prefix[i-1];

			vi nxt_dp(dp.size() + 1);
			rep(i,1,dp.size()) 
				nxt_dp[i] = max(dp[i],dp[i-1]) + 
					    intelligence_checks_prefix[i] + 
					    strength_checks_prefix[dp.size() - i];

			if(dp.size()) {
				nxt_dp[0] = dp[0] + strength_checks_prefix[dp.size()];
				nxt_dp[dp.size()] = dp[dp.size()-1] + intelligence_checks_prefix[dp.size()];
			}

			dp = nxt_dp;

//			cout<<i<<":\n";
//			for(auto i: dp) cout<<i<<' ';
//			cout<<'\n';

			strength_checks_prefix.assign(m+4,0);
			intelligence_checks_prefix.assign(m+4,0);
		}
	}

	cout<<*max_element(all(dp))<<'\n';
}

int main() {
//	freopen("closing.in", "r", stdin);
//	freopen("closing.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
