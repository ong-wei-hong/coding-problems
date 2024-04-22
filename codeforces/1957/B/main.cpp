#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n,k;
	
	cin>>n>>k;
	if(n==1) {
		cout<<k<<'\n';
		return;
	}

	int a=(1<<(31-__builtin_clz(k)))-1;
	if(__builtin_popcount(a)>__builtin_popcount(k)) {
		cout<<a<<' '<<k-a;
		rep(i,2,n) cout<<" 0";
		cout<<'\n';
	} else {
		cout<<k;
		rep(i,1,n) cout<<" 0";
		cout<<'\n';
	}
}




int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;cin>>t;
	while(t--) solve();
}
