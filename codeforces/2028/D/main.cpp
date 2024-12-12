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
vi p[3];
const string s ="qkj";
vector<pair<char,int>> dp,ans;

void solve() {
	cin>>n;
	rep(i,0,3) {
		p[i].resize(n);
		for(auto &j: p[i]) cin>>j,--j;
	}
	
	dp.assign(n,{'\0',-1});
	int mn[3] {n-1,n-1,n-1};

	for(int i=n-2;i>=0;--i) {
		int win=-1;
		rep(j,0,3)
			if(p[j][i] > p[j][mn[j]]) win=j;
		if (win == -1) continue;
		dp[i]={s[win],mn[win]};
//		cout<<i<<" to "<<mn[win]<<':'<<s[win]<<'\n';
		rep(j,0,3) if(p[j][i] < p[j][mn[j]]) mn[j]=i;
	}

	if(dp[0].se == -1) {
		cout<<"NO\n";
		return;
	}

	ans.clear();
	ans.push_back(dp[0]);
	while(ans.back().se != -1) ans.push_back(dp[ans.back().se]);
	ans.pop_back();

	cout<<"YES\n"<<ans.size()<<'\n';
	for(auto &[c,i]: ans) cout<<c<<' '<<(i+1)<<'\n';
}

int main() {
//	freopen("revegetate.in", "r", stdin);
//	freopen("revegetate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
