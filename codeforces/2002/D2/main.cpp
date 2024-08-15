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

constexpr int MAX_N=3e5;
int n,q,fa[MAX_N+1],siz[MAX_N+1],pos[MAX_N+1],i_pos[MAX_N+1];
set<int> child_pos[MAX_N+1];

int solve(int node) {
	if(child_pos[node].empty()) return 1;
	if(*child_pos[node].begin() < pos[node]) return 0;
	int r=*child_pos[node].rbegin();
	if(r+siz[i_pos[r]]>pos[node]+siz[node]) return 0;
	return 1;
}

void solve() {
	cin>>n>>q;

	rep(i,1,n+1) siz[i]=1,child_pos[i].clear();
	rep(i,2,n+1) cin>>fa[i];
	for(int i=n;i>=1;--i) siz[fa[i]] += siz[i];
	// i_pos = p, pos = q
	rep(i,1,n+1) cin>>i_pos[i],pos[i_pos[i]]=i,child_pos[fa[i_pos[i]]].insert(i);

	int cnt=0;
	rep(i,1,n+1) cnt+=solve(i);
	while(q--) {
		int a,b;
		cin>>a>>b;
		int x=i_pos[a],y=i_pos[b];
		set<int> se;
		se.insert(x);
		se.insert(y);
		se.insert(fa[x]);
		se.insert(fa[y]);
		for(auto i: se) if(i) cnt -= solve(i);

		child_pos[fa[x]].erase(a);
		child_pos[fa[y]].erase(b);
		swap(i_pos[a],i_pos[b]);
		swap(pos[x],pos[y]);
		child_pos[fa[x]].insert(b);
		child_pos[fa[y]].insert(a);

		for(auto i: se) if(i) cnt += solve(i);

		cout<<(cnt == n ? "YES\n" : "NO\n");

//		cout<<"pos\n";
//		rep(i,1,n+1) cout<<pos[i]<<' ';
//		cout<<'\n';
//		cout<<"i_pos\n";
//		rep(i,1,n+1) cout<<i_pos[i]<<' ';
//		cout<<'\n';
//		cout<<"child_pos\n";
//		rep(i,1,n+1) {
//			cout<<i<<':';
//			for(auto j: child_pos[i]) cout<<j<<' ';
//			cout<<'\n';
//		}
//		cout<<'\n';
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

