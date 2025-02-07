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

constexpr int MAX_N=300;
int a[MAX_N][MAX_N],n;
vi v;

void solve() {
	cin>>n;
	rep(i,0,n) rep(j,0,n) cin>>a[i][j];
	v.resize(n);

	rep(i,0,n) {
		int k=0;
		for(int j=n-1;j>=0;--j) {
			k += (a[i][j] == 1);
			if (a[i][j] != 1) break;
		}

		v[i] = k;
	}

	sort(all(v));

	int ans=0;
	for(auto i: v) ans += (i >= ans);
	cout<<ans<<'\n';
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
