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

int n,c;
vi a;

void solve() {
	cin>>n>>c;
	a.resize(n);
	for(auto &i : a) {
		cin>>i;
		int j = 0;
		while(i <= c) {
			++j;
			i *= 2;
		}
		i = j;
	}

	int ans = 0, curr_turn = 1;
	sort(all(a));

	for(auto i : a) {
		if (curr_turn > i) {
		       ++ans;
		} else {
			++curr_turn;
		}		
	}
	cout<<ans<<'\n';
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
