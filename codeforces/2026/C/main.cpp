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
deque<int> ones;
vi zeros;

void solve() {
	cin>>n>>s;
	ones.clear();
	zeros.clear();
	rep(i,0,n)
		if (s[i] == '0') zeros.push_back(i+1);
		else if (s[i] == '1') ones.push_back(i+1);

	ll ans=0;
	while(!ones.empty()) {
		auto last_one = ones.back(); ones.pop_back();
		while (zeros.size() && zeros.back() > last_one) {
//			cout<<"bought "<<zeros.back()<<'\n';
			ans += zeros.back();
			zeros.pop_back();
		}

		if(!zeros.empty()) {
//			cout<<"bought "<<zeros.back()<<" free: "<<last_one<<'\n';
			ans += zeros.back(); 
			zeros.pop_back();
		} else if (!ones.empty()) {
//			cout<<"bought "<<ones.front()<<" free: "<<last_one<<'\n';
			ans += ones.front();
			ones.pop_front();
		} else {
//			cout<<"bought "<<last_one<<'\n';
			ans += last_one;
		}
	}

	while(!zeros.empty()) ans += zeros.back(), zeros.pop_back();

	cout<<ans<<'\n';
}

int main() {
//	freopen("fenceplan.in", "r", stdin);
//	freopen("fenceplan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
