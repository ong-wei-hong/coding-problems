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
vi v;
multiset<int> ms;
vector<pii> ops;

void solve() {
	cin>>n;
	v.resize(2*n);
	for(auto &i: v) cin>>i;
	sort(all(v));

	rep(i,0,2*n-1) {
//		cout<<"DEBUG:"<<v[i]<<'\n';
		ms.clear();
		rep(j,0,2*n-1) if(i!=j) ms.insert(v[j]);

		int curr=v[2*n-1];
		ops.clear();
		ops.push_back({v[i],curr});
		while(!ms.empty()) {
			auto it=ms.end();
			--it;
			int a=*it,b=curr-a;
//			cout<<"DEBUG:"<<b<<' '<<a<<'\n';
			ms.erase(it);
			it=ms.find(b);
			if(it==ms.end()) break;
			ms.erase(it);
			ops.push_back({b,a});
			curr=a;
		}

		if(ms.empty()) {
			cout<<"YES\n"<<ops[0].fi+ops[0].se<<'\n';
			for(auto &p: ops) cout<<p.fi<<' '<<p.se<<'\n';
			return;
		}
	}

	cout<<"NO\n";
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

