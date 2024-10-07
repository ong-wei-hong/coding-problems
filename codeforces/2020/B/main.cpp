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

vector<ll> squares;
ll k;

void solve() {
	cin>>k;

	ll lb=k,ub=2e18;
	while(ub-lb>1) {
		ll mid=lb+(ub-lb)/2,num_on=mid-ll(sqrtl(mid));
		if(num_on>=k) ub=mid;
		else lb=mid;
	}

	cout<<ub<<'\n';
}

int main() {
//	freopen("loan.in", "r", stdin);
//	freopen("loan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
