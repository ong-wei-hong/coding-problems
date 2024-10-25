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
string s;

void solve() {
	cin>>n>>s;

	if(s[0] == '1' || s.back() == '1') {
		cout<<"YES\n";
		return;
	}

	rep(i,0,n-1) if(s[i]=='1'&&s[i+1]=='1') {
		cout<<"YES\n";
		return;
	}

	cout<<"NO\n";
}

int main() {
//	freopen("moocast.in", "r", stdin);
//	freopen("moocast.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
