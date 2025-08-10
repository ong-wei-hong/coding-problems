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

int n,a;

void solve() {
	bool valid=true;
	int num=-1;
	cin>>n;
	rep(_,0,n) {
		cin>>a;
		if(a!=-1) {
			if (num == -1) num = a;
			if (num != a) valid = false;
		}
	}

	if (num == 0 || !valid) {
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
	}
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
