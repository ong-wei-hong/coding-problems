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

constexpr int MAX_N=2e5;
int n;
ll a,b,ans[MAX_N+1];
map<ll,int> m;

void solve() {
	cin>>n;
	rep(_,0,n) cin>>a>>b,++m[a],--m[b+1];
	
	ll prv=-1;
	int cnt=0;

	for(auto &it: m) {
		ll nxt=it.fi;
		ans[cnt]+=(nxt-prv);
		cnt+=it.se;
		prv=nxt;
	}

	rep(i,1,n+1) cout<<ans[i]<<" \n"[i==n];
}

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	solve();
}

