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

int n,q;
vector<int> m[16],v;
vector<pii> u;

int ord(string s) {
	int ans=0;
	for(auto c: s) {
		if(c=='B') ans|=1;
		if(c=='G') ans|=2;
		if(c=='R') ans|=4;
		if(c=='Y') ans|=8;
	}
	return ans;
}

void solve() {
	cin>>n>>q;

	for(auto &it: m) it.clear();
	v.resize(n);
	rep(i,0,n) {
		string s;
		cin>>s;
		int k=ord(s);
		m[k].push_back(i);
		v[i]=k;
	}

	u.resize(n);
	rep(i,0,n) {
		int l=INT_MIN,r=INT_MAX,keys[6] {3,5,9,6,10,12};
		for(auto k: keys) {
			if(k==v[i]||(k&v[i])==0) continue;
			auto it=upper_bound(all(m[k]),i);

			if(it!=m[k].end()) r=min(r,*it);
			if(it!=m[k].begin()) {
				--it;
				l=max(l,*it);
			}
		}
		u[i]={l,r};
	}

	while(q--) {
		int a,b;
		cin>>a>>b;
		--a,--b;
		if(a>b) swap(a,b);

		if(v[a]&v[b]) {
			cout<<b-a<<'\n';
			continue;
		}

		int ans=INT_MAX;
		if(u[a].fi!=INT_MIN) ans=min(ans,a-u[a].fi+b-u[a].fi);
		if(u[a].se!=INT_MAX) ans=min(ans,u[a].se-a+abs(b-u[a].se));
		if(u[b].fi!=INT_MIN) ans=min(ans,abs(u[b].fi-a)+b-u[b].fi);
		if(u[b].se!=INT_MAX) ans=min(ans,u[b].se-a+u[b].se-b);

		if(ans==INT_MAX) cout<<"-1\n";
		else cout<<ans<<'\n';
	}

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

