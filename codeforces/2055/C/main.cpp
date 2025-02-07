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

constexpr int MAX_N=1e3;
int n,m;
ll a[MAX_N][MAX_N];
string path;

void solve(int x, int y) {
	ll rSum=0;
	bool rValid=1;

	rep(i,0,n) {
		if (i == x) continue;
		if (a[i][y] == INT_MAX) {
			rValid=0;
			break;
		}
		rSum += a[i][y];
	}


	if (!rValid) {
		rSum = 0;
		rep(j,0,m) rSum += (j != y) * a[x][j];
	}

	a[x][y] = -rSum;
}

void solve() {
	cin>>n>>m>>path;
	rep(i,0,n) rep(j,0,m) cin>>a[i][j];

	{
		int x,y;
		x=y=0;
		a[x][y] = INT_MAX;
		for(auto c: path) {
			if (c == 'D') ++x;
			if (c == 'R') ++y;
			a[x][y] = INT_MAX;
		}
	}

	{
		int x,y;
		x=y=0;
		solve(x,y);
		for(auto c: path) {
			if (c == 'D') ++x;
			if (c == 'R') ++y;
			solve(x,y);
		}
	}

	rep(i,0,n) rep(j,0,m) cout<<a[i][j]<<" \n"[j==m-1];
}


int main() {
//	freopen("gates.in", "r", stdin);
//	freopen("gates.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
