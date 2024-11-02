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
vi a;

void solve() {
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;
	sort(all(a));

	int l=0,ans=n-2;
	rep(r,2,n) {
		while(r-l>=2 && a[l] + a[l+1] <= a[r]) l++;
		ans = min(ans,n - (r - l + 1));
	}

	cout<<ans<<'\n';

}


int main() {
//	freopen("fenceplan.in", "r", stdin);
//	freopen("fenceplan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
