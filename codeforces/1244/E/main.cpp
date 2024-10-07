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
ll k;
vector<ll> a;
map<ll, pair<ll,ll>> prefix;

ll solve(vector<ll> &a) {
	ll min_diff = INT_MAX;
	ll total=0,cnt=0;
	prefix.clear();
	for(auto i: a) total+=i,prefix[i]={total,++cnt};

//	for(auto &it: prefix) cout<<it.fi<<':'<<it.se.fi<<','<<it.se.se<<'\n';

	for(auto i: a) {
		ll lb=i,ub=a.back();
		ll curr_k = k - 1LL * prefix[i].se * i + prefix[i].fi;
//		cout<<i<<':'<<curr_k<<'\n';
		if (curr_k < 0) break;
		while(lb<ub) {
			ll mid=(lb+ub)/2;
			auto it=prefix.upper_bound(mid);
			--it;

			ll curr = total-(it->se.fi)-(a.size()-it->se.se)*mid;
			if(curr<=curr_k) ub=mid;
			else lb=mid+1;
		}

//		cout<<"lower:"<<i<<" upper:"<<ub<<'\n';
		min_diff = min(min_diff, ub-i);

	}

	return min_diff;
}

void solve() {
	cin>>n>>k;
	a.resize(n);
	for(auto &i: a) cin>>i;

	sort(all(a));
	ll min_diff = solve(a);
	for(auto &i: a) i=1e9+1-i;
	reverse(all(a));
	min_diff = min(solve(a), min_diff);

	cout<<min_diff<<'\n';
}

int main() {
//	freopen("loan.in", "r", stdin);
//	freopen("loan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
