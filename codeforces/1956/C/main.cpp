#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n;
	cin>>n;

	int s=0,j=1;
	rep(i,1,n+1) s+=i*j,j+=2;

	cout<<s<<' '<<2*n<<'\n';
	for(int i=n;i>0;--i) {
		cout<<"1 "<<i;
		rep(j,1,n+1) cout<<' '<<j;
		cout<<'\n';

		cout<<"2 "<<i;
		rep(j,1,n+1) cout<<' '<<j;
		cout<<'\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin>>t;
	while(t--) solve();
}
