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

constexpr int MAX_N=1e5;
int n,m,k,l,r;
ll a[MAX_N+2],b[MAX_N+2],op[MAX_N+1][3],c[MAX_N+2];

void solve() {
}


int main() {
	//freopen("lazy.in", "r", stdin);
	//freopen("lazy.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>m>>k;
	rep(i,1,n+1) cin>>a[i];
	rep(i,1,m+1) cin>>op[i][0]>>op[i][1]>>op[i][2];
	rep(_,0,k) {
		cin>>l>>r;
		++b[l];
		--b[r+1];
	}

	ll k=0;
	rep(i,1,m+1) {
		k+=b[i];
		c[op[i][0]]+=k*op[i][2];
		c[op[i][1]+1]-=k*op[i][2];
	}

	k=0;
	rep(i,1,n+1) {
		k+=c[i];
		cout<<a[i]+k<<" \n"[i==n];
	}
}
