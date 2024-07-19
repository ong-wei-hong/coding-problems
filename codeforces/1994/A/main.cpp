#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define LSB(x) (x)&(-x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

constexpr int MAX_N=10;
int a[MAX_N][MAX_N],n,m;

void solve() {
	cin>>n>>m;
	rep(i,0,n) rep(j,0,m) cin>>a[i][j];

	if(n==1&&m==1) {
		cout<<"-1\n";
		return;
	}

	rep(i,0,n) rep(j,0,m) {
		int k=(a[i][j]+1)%(n*m);
		if(k==0) k=n*m;
		cout<<k<<" \n"[j==m-1];
	}
	
}


int main() {
	//freopen("lazy.in", "r", stdin);
	//freopen("lazy.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
	
