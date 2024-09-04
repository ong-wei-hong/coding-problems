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
vector<vi> al;
string s;

void solve() {
	cin>>n;
	al.assign(n+1,vi());
	rep(_,0,n-1) {
		int u,v;
		cin>>u>>v;
		al[u].push_back(v);
		al[v].push_back(u);
	}

	cin>>s;

	int cnt2,cntLeaf0,cntLeaf1,cntLeaf2;
	cntLeaf0=cntLeaf1=cntLeaf2=cnt2=0;
	rep(i,2,n+1) if(al[i].size()==1) {
		cntLeaf0+=(s[i-1]=='0');
		cntLeaf1+=(s[i-1]=='1');
		cntLeaf2+=(s[i-1]=='?');
	}
	for(auto ch: s) cnt2+=(ch=='?');

	if(s[0]=='?') {
		--cnt2;
		if(cntLeaf0!=cntLeaf1) cout<<max(cntLeaf1,cntLeaf0)+(cntLeaf2/2)<<'\n';
		else {
			if((cnt2-cntLeaf2)&1) cout<<cntLeaf0+(cntLeaf2+1)/2<<'\n';
			else cout<<cntLeaf0+(cntLeaf2/2)<<'\n';
		}
	} else {
		cout<<(cntLeaf2+1)/2+(s[0]=='1'?cntLeaf0:cntLeaf1)<<'\n';
	}

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
