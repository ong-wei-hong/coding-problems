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

int n;
string houses[3];
int dp[int(4e4)][3];

int vote(pii a, pii b, pii c) {
	int cnt=0;
	cnt += houses[a.se][a.fi] == 'A';
	cnt += houses[b.se][b.fi] == 'A';
	cnt += houses[c.se][c.fi] == 'A';

	return cnt >= 2;
}

void solve() {
	cin>>n>>houses[0]>>houses[1];

	dp[0][1] = vote({0,0},{0,1},{1,0});
	dp[0][2] = vote({0,0},{0,1},{1,1});

	dp[0][0] = vote({0,0},{1,0},{2,0}) + vote({0,1},{1,1},{2,1});
	dp[0][0] = max(dp[0][0], dp[0][1] + vote({1,1},{2,0},{2,1}));
	dp[0][0] = max(dp[0][0], dp[0][2] + vote({1,0},{2,0},{2,1}));

	rep(i,1,n/3) {
		dp[i][1] = dp[i-1][0] + vote({i*3,0},{i*3,1},{i*3+1,0});
		dp[i][1] = max(dp[i][1], dp[i-1][1] + vote({i*3-1,0},{i*3,0},{i*3+1,0}) + vote({i*3-2,1},{i*3-1,1},{i*3,1}));

		dp[i][2] = dp[i-1][0] + vote({i*3,0},{i*3,1},{i*3+1,1});
		dp[i][2] = max(dp[i][2], dp[i-1][2] + vote({i*3-2,0},{i*3-1,0},{i*3,0}) + vote({i*3-1,1},{i*3,1},{i*3+1,1}));

		dp[i][0] = dp[i-1][0] + vote({i*3,0},{i*3+1,0},{i*3+2,0}) + vote({i*3,1},{i*3+1,1},{i*3+2,1});
		dp[i][0] = max(dp[i][0], dp[i][1] + vote({i*3+1,1},{i*3+2,1},{i*3+2,0}));
		dp[i][0] = max(dp[i][0], dp[i][2] + vote({i*3+1,0},{i*3+2,0},{i*3+2,1}));
	}

	cout<<dp[n/3-1][0]<<'\n';
}

int main() {
//	freopen("loan.in", "r", stdin);
//	freopen("loan.out", "w", stdout);
//	cin.tie(0)->sync_with_stdio(0);
//	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
