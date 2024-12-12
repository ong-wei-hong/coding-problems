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

ll n,k;
deque<ll> ans;

void solve() {
	cin>>n>>k;
	ans.clear();
	if(n<=60 && (1LL<<(n-1))<k) {
		cout<<"-1\n";
		return;
	}

	ll mask = k-1;

	ans.push_back(n);
	rep(i,0,min(64LL,n-1)) {
		if(mask&(1LL<<i)) ans.push_back(n-i-1);
		else ans.push_front(n-i-1);
	}

	rep(i,64,n-1) ans.push_front(n-i-1);

	for(auto i: ans) cout<<i<<' ';
	cout<<'\n';
}

int main() {
//	freopen("lightson.in", "r", stdin);
//	freopen("lightson.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
