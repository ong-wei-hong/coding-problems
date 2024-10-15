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

int n,k;
vi a;

void solve() {
	cin>>n>>k;
	a.resize(n);
	for(auto &i: a) cin>>i;
	int geq_med_cnt = k/2+1;

	int lb=1,ub=n;
	while(lb<ub) {
		int mid=(lb+ub+1)/2;
		vi geq_mid_prefix(n);
		geq_mid_prefix[0] = a[0] >= mid ? 1 : -1;
		rep(i,1,n) geq_mid_prefix[i] = geq_mid_prefix[i-1] + (a[i] >= mid ? 1 : -1);
		int mn=0,diff=0;
		rep(i,k-1,n) {
			mn = min(mn, geq_mid_prefix[i-k]);
			diff = max(diff, geq_mid_prefix[i] - mn);
		}

		if(diff>0) lb=mid;
		else ub=mid-1;
	}

	cout<<lb<<'\n';
}

int main() {
//	freopen("loan.in", "r", stdin);
//	freopen("loan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
