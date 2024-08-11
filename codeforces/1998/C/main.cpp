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
vector<pii> v;

void solve() {
	cin>>n>>k;
	v.resize(n);
	for(auto &i: v) cin>>i.fi;
	for(auto &i: v) cin>>i.se;
	sort(all(v));

	ll ans=0;
	rep(i,0,n) if(v[i].se==1) {
		if(i<n/2) ans=max(ans,0LL+v[i].fi+k+v[n/2].fi);
		else ans=max(ans,0LL+v[i].fi+k+v[(n-2)/2].fi);
	}

	int lb=0,ub=2e9,curr=0;
	while(lb<=ub) {
		int mid=(0LL+lb+ub)/2,cnt=0,ops=0;
		rep(i,0,n-1) if(v[i].se==0) cnt+=(v[i].fi>=mid);
		for(int i=n-2;cnt<(n+1)/2&&i>=0;--i) if(v[i].se==1) {
			++cnt;
			ops+=max(0,mid-v[i].fi);
			if(ops>k) break;
		}

//		cout<<"mid:"<<mid<<",cnt:"<<cnt<<",ops:"<<ops<<",valid:"<<(cnt>=(n+1)/2&&ops<=k)<<'\n';
		if(cnt>=(n+1)/2&&ops<=k) curr=mid,lb=mid+1;
		else ub=mid-1;
	}

	ans=max(ans,0LL+v[n-1].fi+curr);
	cout<<ans<<'\n';
}

int main() {
	//freopen("measurement.in", "r", stdin);
	//freopen("measurement.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();

}
