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
map<int,int> m;
vi v;

void solve() {
	cin>>n;
	m.clear();
	while(n--) {
		int a;
		cin>>a;
		++m[a];
	}

	v.resize(m.size());
	int i=0;
	for(auto &it: m) v[i++]=it.second;

	int s=0;
	for(int i=v.size()-1;i>=0;--i) {
		s+=v[i];
		if(s&1) {
			cout<<"YES\n";
			return;
		}
	}

	cout<<"NO\n";
}

int main() {
	//freopen("art.in", "r", stdin);
	//freopen("art.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
