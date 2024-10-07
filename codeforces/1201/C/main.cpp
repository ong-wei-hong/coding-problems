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
vi v;

void solve() {
	cin>>n>>k;
	v.resize(n);
	for(auto &i: v) cin>>i;
	sort(all(v));

	ll lb=1,ub=2e9,ans;
	while(lb<=ub) {
		int mid=(lb+ub)/2;
		ll curr=0;
		rep(i,n/2,n) curr+=max(0,mid-v[i]);

		if(curr<=k) lb=mid+1,ans=mid;
		else ub=mid-1;
	}

	cout<<ans<<'\n';
}

int main() {
//	freopen("berries.in", "r", stdin);
//	freopen("berries.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();

}
