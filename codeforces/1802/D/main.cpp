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
vector<pii> v;
multiset<int> ms;

void solve() {
	cin>>n;
	v.resize(n);
	for(auto &p: v) cin>>p.fi>>p.se,p.se=-p.se;
	sort(rall(v));

	ms.clear();
	for(auto &p: v) p.se=-p.se,ms.insert(p.se);
	int ans=INT_MAX,prev=-1;
	for(auto &p: v) {
		ms.erase(ms.find(p.se));
		if(prev!=-1) ans=min(ans,abs(p.fi-prev));
		auto it=ms.lower_bound(p.fi);
		if(it!=ms.end()) ans=min(ans,abs(p.fi-max(*it,prev)));
		if(it!=ms.begin()) ans=min(ans,abs(p.fi-max(*(--it),prev)));
		prev=max(prev,p.se);
	}

	cout<<ans<<'\n';

}

int main() {
//	freopen("berries.in", "r", stdin);
//	freopen("berries.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
