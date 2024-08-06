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

vector<string> v;


int main() {
	//freopen("split.in", "r", stdin);
	//freopen("split.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	int n;
	cin>>n;
	v.resize(n);
	for(auto &i: v) cin>>i;

	sort(all(v),[](string s, string t) {
		return (s+t) < (t+s);
	});
	for(auto &s: v) cout<<s;
	cout<<'\n';
}
