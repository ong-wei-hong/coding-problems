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

int n,m;
vi cities,towers;

void solve() {
	int cities_i,towers_i;
	int ans=0;
	for(cities_i=towers_i=0;cities_i<n;++cities_i) {
		while(towers_i<m-1&&
				abs(cities[cities_i]-towers[towers_i+1])<=
				abs(cities[cities_i]-towers[towers_i])) ++towers_i;
		ans=max(ans,abs(cities[cities_i]-towers[towers_i]));
	}

	cout<<ans<<'\n';
}

int main() {
	//freopen("meetings.in", "r", stdin);
	//freopen("meetings.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin>>n>>m;
	cities.resize(n);
	towers.resize(m);
	sort(all(cities));
	sort(all(towers));
	for(auto &i: cities) cin>>i;
	for(auto &i: towers) cin>>i;

	solve();
}

