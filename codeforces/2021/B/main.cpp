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

int n,x,a;
map<int,int> freq_cnt;

void solve() {
	cin>>n>>x;
	freq_cnt.clear();
	rep(_,0,n) {
		cin>>a;
		freq_cnt[a]++;
	}

	int i=0;
	while(1) {
		int cnt = freq_cnt[i];
		if(cnt == 0) {
			cout<<i<<'\n';
			return;
		}
		freq_cnt[i+x] += cnt - 1;
		++i;
	}
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
