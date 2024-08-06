#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define LSB(x) (x) & (-x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <class T>
using Tree =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX_N=5e5;
int n,k,a[MAX_N],dp[MAX_N],b[MAX_N];

bool check(int med) {
	rep(i,0,n) 
		if(a[i]>=med) b[i]=1;
		else b[i]=-1;

	dp[0]=b[0];
	rep(i,1,n)
		if(i%k==0) dp[i]=max(dp[i-k],b[i]);
		else {
			dp[i]=dp[i-1]+b[i];
			if(i>k) dp[i]=max(dp[i],dp[i-k]);
		}

	return dp[n-1]>0;
}

void solve() {
	cin>>n>>k;
	rep(i,0,n) cin>>a[i];

	int lb=1,ub=1e9;
	while(lb<=ub) {
		int mid=(lb+ub)/2;
		if(check(mid)) lb=mid+1;
		else ub=mid-1;
	}

	cout<<ub<<'\n';
}

int main() {
	//freopen("meetings.in", "r", stdin);
	//freopen("meetings.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();

}

