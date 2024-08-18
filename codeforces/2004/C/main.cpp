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

int N,K;
vi v;

void solve() {
	cin>>N>>K;
	v.resize(N);
	for(auto &i: v) cin>>i;
	sort(rall(v));
	for(int i=1;i<N;i+=2) {
		int m=min(v[i-1]-v[i],K);
		K-=m;
		v[i]+=m;
	}
	ll ans=0;
	for(int i=0,j=1;i<N;++i,j*=-1) {
		ans += j*v[i];
	}
	cout<<ans<<'\n';
}

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}

