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
vector<string> s;
string narek="narek";

void solve() {
	cin>>n>>m;
	s.resize(n);
	for(auto &i: s) cin>>i;

	int dp[5];
	dp[0]=0;
	dp[1]=dp[2]=dp[3]=dp[4]=INT_MIN;

	for(auto &st: s) {
		int ndp[5];
		memcpy(ndp,dp,sizeof dp);
		rep(i,0,5) {
			if(dp[i] == INT_MIN) continue;
			int curr_dp=dp[i],idx=i;
			for(auto c: st) {
				int j=narek.find(c);
				if(j == -1) continue;
				if(idx == j) {
					curr_dp++;
					idx = (idx+1)%5;
				} else {
					curr_dp--;
				}
			}

			ndp[idx]=max(ndp[idx],curr_dp);
		}
		memcpy(dp,ndp, sizeof dp);
	}

	int ans=0;
	rep(i,0,5) if(dp[i] != INT_MIN) {
		ans=max(ans,dp[i]-2*i);
	}

	cout<<ans<<'\n';
}

int main() {
//	freopen("angry.in", "r", stdin);
//	freopen("angry.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
