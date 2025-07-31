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

const int MAX_N=1000;
int m[MAX_N][MAX_N],a[MAX_N],n;
ll dp[2][MAX_N];

pair<bool,bool> check_row(int i, bool addToI) {
	bool valid0,valid1;
	valid0=valid1=true;

	rep(j,0,n) {
		if (m[i][j] + addToI == m[i+1][j]) {
			valid0=false;
		}
		if (m[i][j] + addToI == m[i+1][j] + 1) {
			valid1 = false;
		}
	}

	return {valid0, valid1};
}

ll cost_dp() {
	dp[0][0] = 0;
	dp[1][0] = a[0];

	rep(i,1,n) {
		auto [valid00, valid01] = check_row(i-1,false);
		auto [valid10, valid11] = check_row(i-1,true);

		dp[0][i] = dp[1][i] = LLONG_MAX;
		if (valid00 && dp[0][i-1] != LLONG_MAX) dp[0][i] = dp[0][i-1];
		if (valid01 && dp[0][i-1] != LLONG_MAX) dp[1][i] = dp[0][i-1] + a[i];
		if (valid10 && dp[1][i-1] != LLONG_MAX) dp[0][i] = min(dp[0][i], dp[1][i-1]);
		if (valid11 && dp[1][i-1] != LLONG_MAX) dp[1][i] = min(dp[1][i], dp[1][i-1] + a[i]);
	}

	return min(dp[0][n-1], dp[1][n-1]);
}

void transpose_m() {
	rep(i,0,n) rep(j,i+1,n) {
		swap(m[i][j],m[j][i]);
	}
}

void solve() {
	cin>>n;
	rep(i,0,n) rep(j,0,n) {
		cin>>m[i][j];
	}

	rep(i,0,n) cin>>a[i];

	ll cost1 = cost_dp();

	rep(i,0,n) cin>>a[i];

	if(cost1 == LLONG_MAX) {
		cout<<"-1\n";
		return;
	}

	transpose_m();
	ll cost2 = cost_dp();

	if (cost2 == LLONG_MAX) {
		cout<<"-1\n";
		return;
	}

	cout<<cost1 + cost2<<'\n';
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
