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

void solve() {
	cin>>n;
	string ans="";
	bool prefix=0;
	int res;

	while(ans.size()!=n) {
		if(prefix) {
			cout<<"? 0"+ans<<'\n';
			cout.flush();
			cin>>res;
			if(res==-1) exit(0);
			if(res==1) ans = "0" + ans;
			else ans = "1" + ans;
		} else {
			cout<<"? "<< ans + "0"<<'\n';
			cout.flush();
			cin>>res;
			if(res==-1) exit(0);
			if(res == 1) {
				ans = ans + "0";
				continue;
			}
			cout<<"? " << ans + "1"<<'\n';
			cout.flush();
			cin>>res;
			if(res == -1) exit(0);
			if(res == 1) ans = ans + "1";
			else prefix=1;
		}
	}

	cout<<"! "<<ans<<'\n';
	cout.flush();

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
