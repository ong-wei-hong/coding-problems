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
 
int n,m,l;
vi a;

void solve() {
	cin>>n>>m;
	int maxi=0;
	while(n--) {
		cin>>l;
		a.resize(l);
		for(auto &i: a) cin>>i;
		sort(all(a));

		int curr=0;
		rep(i,0,l) if(curr==a[i]) ++curr;
		++curr;
		rep(i,0,l) if(curr==a[i]) ++curr;
		maxi=max(maxi,curr);
	}

	ll ans=1LL*(min(m,maxi)+1)*maxi;
	if(maxi<m) ans+=1LL*(m-maxi)*(maxi+1+m)/2;
	cout<<ans<<'\n';
}

int main() {
//	freopen("lemonade.in", "r", stdin);
//	freopen("lemonade.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
