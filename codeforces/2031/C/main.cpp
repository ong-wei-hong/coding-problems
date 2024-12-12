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
vi v;

void solve() {
	cin>>n;

	if (n % 2 == 1) {
		if (n < 27) {
			cout<<"-1\n";
			return;
		}

		cout<<"1 ";
		rep(i,0,4) cout<<(i+3)<<' '<<(i+3)<<' ';
		cout<<"1 2 ";
		rep(i,0,7) cout<<(i+7)<<' '<<(i+7)<<' ';
		cout<<"1 2 ";
		rep(i,0,(n-27)/2) cout<<(i+14)<<' '<<(i+14)<<' ';
		cout<<'\n';
		return;
	}

	rep(i,0,n/2) cout<<(i+1)<<' '<<(i+1)<<' ';
	cout<<'\n';
}

int main() {
//	freopen("perimeter.in", "r", stdin);
//	freopen("perimeter.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
