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
vector<bool> unused;
vi rOrder;

void solve() {
	cin>>n;
	unused.assign(n+1,1);
	rOrder.clear();
	int mx=0;

	if(n&1) {
		mx=n;
		unused[1]=unused[3]=unused[n-1]=unused[n]=0;
		rOrder.push_back(n);
		rOrder.push_back(n-1);
		rOrder.push_back(3);
		rOrder.push_back(1);
	} else {
		mx = (1 << (32-__builtin_clz(n)))-1;
		int comp = mx ^ n;
		unused[n] = 0;
		rOrder.push_back(n);
		if (comp == 1) {
			assert (n >= 6);
			unused[1] = unused[3] = 0;
			rOrder.push_back(1);
			rOrder.push_back(3);
		} else if (comp == 3) {
			assert (n >= 7);
			unused[3] = unused[7] = 0;
			rOrder.push_back(3);
			rOrder.push_back(7);
		} else {
			unused[1] = unused[3] = unused[comp-1] = unused[comp] = 0;
			rOrder.push_back(comp);
			rOrder.push_back(comp-1);
			rOrder.push_back(3);
			rOrder.push_back(1);
		}
	}

	cout<<mx<<'\n';
	rep(i,1,n+1) if(unused[i]) cout<<i<<' ';
	for(int i=rOrder.size()-1;i>=0;--i) cout<<rOrder[i]<<' ';
	cout<<'\n';
}

int main() {
//	freopen("fenceplan.in", "r", stdin);
//	freopen("fenceplan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
