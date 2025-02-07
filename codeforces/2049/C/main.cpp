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
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n,x,y;
vi ans;

void solve() {
	cin>>n>>x>>y;
	ans.assign(n,-1);
	--x,--y;
	if(n&1) {
		ans[x]=2;

		int curr=0;
		rep(i,x+1,n) {
			ans[i]=curr;
			curr=1-curr;
		}

		curr=1;
		for(int i=x-1;i>=0;--i) {
			ans[i]=curr;
			curr=1-curr;
		}
	} else if((y-x)&1) {
		int curr=0;
		rep(i,0,n) {
			ans[i]=curr;
			curr=1-curr;
		}
	} else if(n==4) {
		ans[x]=0;
		ans[y]=1;
		for(auto &i: ans) if(i==-1) i=2;
	} else {
		int k = (x-2+n)%n;
		rep(i,0,6) {
			ans[k]="012012"[i] - '0';
			k = (k+1)%n;
		}

		int curr=0;
		while(ans[k]==-1) {
			ans[k]=curr;
			curr = 1-curr;
			k=(k+1)%n;
		}
	}

	for(auto i: ans) cout<<i<<' ';
	cout<<'\n';

}

int main() {
//	freopen("gates.in", "r", stdin);
//	freopen("gates.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
