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

int n,k,a;
map<int,int> deck_freq;

void solve() {
	cin>>n>>k;
	deck_freq.clear();
	rep(_,0,n) {
		cin>>a;
		++deck_freq[a];
	}

	int cnt=0,nxt_card=deck_freq.begin()->fi,curr_sum=0,ans=0;

	while(nxt_card <= deck_freq.rbegin()->fi) {
		auto it = deck_freq.lower_bound(nxt_card);
		if (it->fi != nxt_card) {
			nxt_card = it->fi;
			cnt = curr_sum = 0;
			continue;
		}

		++cnt;
		curr_sum += it->se;
		if (cnt > k) curr_sum -= deck_freq[nxt_card - k],cnt=k;
		ans = max(ans, curr_sum);

		++nxt_card;
	}

	cout<<ans<<'\n';
}

int main() {
//	freopen("loan.in", "r", stdin);
//	freopen("loan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
