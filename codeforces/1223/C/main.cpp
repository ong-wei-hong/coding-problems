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

int n,x,y;
vector<ll> p;
ll k,a,b;

void solve() {
	cin>>n;
	p.resize(n);
	for(auto &i: p) cin>>i;
	sort(rall(p));
	cin>>x>>a>>y>>b>>k;
	if(x<y) swap(x,y),swap(a,b);

	int lb=1,ub=n,ans=-1;
	while(lb<=ub) {
		int mid=(lb+ub)/2,x_y=mid/(lcm(a,b)),x_only=(mid/a)-x_y,y_only=(mid/b)-x_y;
		ll curr=0;
		int i=0;
		rep(_,0,x_y) curr+=(p[i++]*(x+y))/100;
		rep(_,0,x_only) curr+=(p[i++]*x)/100;
		rep(_,0,y_only) curr+=(p[i++]*y)/100;

		if(curr>=k) {
			ub=mid-1;
			ans=mid;
		} else {
			lb=mid+1;
		}
	}

	cout<<ans<<'\n';
}

int main() {
//	freopen("cardgame.in", "r", stdin);
//	freopen("cardgame.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
