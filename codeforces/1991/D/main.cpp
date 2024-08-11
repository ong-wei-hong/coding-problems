#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define LSB(x) (x) & (-x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <class T>
using Tree =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;

void solve() {
	cin>>n;
	if(n<6) {
		if(n==1) {
			cout<<"1\n1\n";
			return;
		}
		if(n<=5) cout<<((n-2)/2)+2<<'\n';
	
		rep(i,1,min(n+1,6)) cout<<"012233"[i]<<' ';
		cout<<'\n';
		return;
	}

	cout<<4<<'\n';
	rep(i,1,n+1) cout<<(i%4)+1<<' ';
	cout<<'\n';

}

int main() {
	//freopen("meetings.in", "r", stdin);
	//freopen("meetings.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();

}

