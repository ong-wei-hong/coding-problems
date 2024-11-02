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

const int MAX_N=2e5;
int n,m,x,y;
unordered_set<int> al[MAX_N];
set<int> unvis;
vi comps;

int dfs(int i) {
	int cnt=1;
	for(auto it=unvis.begin();it!=unvis.end();) {
		if(al[i].count(*it)) ++it;
		else {
			int curr = *it;
			unvis.erase(curr);
			cnt += dfs(curr);
			it = unvis.upper_bound(curr);
		}
	}

	return cnt;
}

void solve() {
	cin>>n>>m;
	rep(_,0,m) {
		cin>>x>>y;
		--x,--y;
		al[x].insert(y);
		al[y].insert(x);
	}

	rep(i,0,n) unvis.insert(i);

	rep(i,0,n) if(unvis.count(i)) {
		unvis.erase(i);
		comps.push_back(dfs(i));
	}

	sort(all(comps));
	cout<<comps.size()<<'\n';
	for(auto i: comps) cout<<i<<' ';
	cout<<'\n';
}


int main() {
//	freopen("fenceplan.in", "r", stdin);
//	freopen("fenceplan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
