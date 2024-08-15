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

constexpr int MAX_N=65535;
int n,q,fa[MAX_N+1],siz[MAX_N+1],pos[MAX_N+1],i_pos[MAX_N+1];
set<int> child[MAX_N+1];

int solve(int node) {
	if(node==0) return 0;
	if(siz[node]==1) return 1;

	int lc=2*node,rc=2*node+1,a=min(i_pos[lc],i_pos[rc]);
	if(a<i_pos[node]) return 0;

	a=max(i_pos[lc],i_pos[rc]);
	return (i_pos[node]+siz[node]>=a+siz[lc]);
}

void solve() {
	cin>>n>>q;
	rep(i,1,n+1) siz[i]=1;
	rep(i,2,n+1) cin>>fa[i];
	for(int i=n;i>=1;--i) siz[fa[i]]+=siz[i];
	rep(i,1,n+1) cin>>pos[i],i_pos[pos[i]]=i;

	int k=0;
	rep(i,1,n+1) k+=solve(i);

	while(q--) {
		int a,b;
		cin>>a>>b;
		int n1=pos[a],n2=pos[b];

		set<int> se;
		se.insert(n1);
		se.insert(n2);
		se.insert(fa[n1]);
		se.insert(fa[n2]);

		for(auto i: se) if(i) k-=solve(i);

		swap(pos[a],pos[b]);
		swap(i_pos[n1],i_pos[n2]);

		for(auto i: se) k+=solve(i);

		//rep(i,1,n+1) cout<<pos[i]<<" \n"[i==n];
		//for(auto i: se) if(i) cout<<i<<':'<<solve(i)<<',';
		//cout<<'\n';


		cout<<(k==n?"YES\n":"NO\n");
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

