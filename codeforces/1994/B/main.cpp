#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define LSB(x) (x)&(-x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

int n;
string s,t;

void solve() {
	cin>>n>>s>>t;
	rep(i,0,n) {
		if(s[i]=='1') break;
		if(s[i]=='0'&&t[i]=='1') {
			cout<<"No\n";
			return;
		}
	}

	cout<<"Yes\n";
}


int main() {
	//freopen("lazy.in", "r", stdin);
	//freopen("lazy.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
	
