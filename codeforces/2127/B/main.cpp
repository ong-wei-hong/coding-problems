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

int n,x,a,b;
char c;

void solve() {
	cin>>n>>x;
	a=0,b=n+1;
	rep(i,1,n+1) {
		cin>>c;
		if(c == '#') {
			if (i < x) a = i;
			else b = min(b,i);
		}
	}

	cout<<max(min(x,n+2-b),min(a+1,n+1-x))<<'\n';
}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) {
		solve();
	}
}
