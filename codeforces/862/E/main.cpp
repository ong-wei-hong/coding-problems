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

int n,m,q,l,r;
vector<ll> a,b;
ll x;

void solve() {
	cin>>n>>m>>q;
	a.resize(n);
	for(auto &i: a) cin>>i;
	b.resize(m);
	for(auto &i: b) cin>>i;

	ll sum_a = 0,sum_b=0;
	for(int i=0,j=1;i<n;++i,j=-j) sum_a+=j*a[i];
	set<ll> b_sums;
	for(int i=0,j=-1;i<n;++i,j=-j) sum_b+=j*b[i];
	b_sums.insert(sum_b);

	{
		int k=n&1?-1:1;
		for(int i=0;i<m-n;++i) {
			sum_b+=b[i];
			sum_b=k*b[i+n]-sum_b;
			b_sums.insert(sum_b);
		}
	}
	
	{
		ll ans=LLONG_MAX;
		auto it=b_sums.upper_bound(-sum_a);
		if(it!=b_sums.end()) ans=min(ans,abs(sum_a+(*it)));
		if(it!=b_sums.begin()) {
			--it;
			ans=min(ans,abs(sum_a+(*it)));
		}
		cout<<ans<<'\n';
	}

	while(q--) {
		cin>>l>>r>>x;
		if((r-l+1)&1) {
			int k=l&1?1:-1;
			sum_a+=k*x;
		}
		ll ans=LLONG_MAX;
		auto it=b_sums.upper_bound(-sum_a);
		if(it!=b_sums.end()) ans=min(ans,abs(sum_a+(*it)));
		if(it!=b_sums.begin()) {
			--it;
			ans=min(ans,abs(sum_a+(*it)));
		}
		cout<<ans<<'\n';
	}
}

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}

