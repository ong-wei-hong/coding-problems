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

constexpr ll MOD=1e9+7;
int n;
vector<ll> a;

void solve() {
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;
	ll offset=0;
	sort(all(a));
	offset=a[0];
	for(auto &i: a) i-=offset;

	for(;n!=1;--n) {
		std::priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
		vi v(n-1);
		vector<ll> b;
		iota(all(v),1);
		rep(i,0,n-1) pq.push({a[i]+a[i+1],i});

		while(b.size()!=n-1) {
			auto p=pq.top();pq.pop();
			b.push_back(p.fi);

			++v[p.se];
			if(v[p.se]!=n) pq.push({a[p.se]+a[v[p.se]],p.se});
		}

		a=b;
		ll curr_offset=a[0];
		for(auto &i: a) i-=curr_offset;
		offset=(curr_offset+2*offset)%MOD;
	}

	cout<<(a[0]+offset)%MOD<<'\n';

}

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}

