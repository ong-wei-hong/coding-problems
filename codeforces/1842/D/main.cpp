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
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n,m,u,v;
ll c;
vector<vector<pair<int,ll>>> al;

void solve() {
	cin>>n>>m;
	al.resize(n);
	rep(_,0,m) {
		cin>>u>>v>>c;
		--u,--v;
		al[u].push_back({v,c});
		al[v].push_back({u,c});
	}

	vector<ll> sssp(n,LLONG_MAX);
	std::priority_queue<pair<ll,int>> pq;
	pq.push({0,0});
	while(!pq.empty()) {
		auto [c,v] = pq.top(); pq.pop();
		if (c >= sssp[v]) {
			continue;
		}

		sssp[v] = c;
		for(const auto &it: al[v]) if(c + it.se < sssp[it.fi]) {
			pq.push({c + it.se, it.fi});
		}
	}

	if (sssp[n-1] == LLONG_MAX) {
		cout<<"inf\n";
		return;
	}

	vector<pair<ll,int>> sssp_pairs;
	rep(i,0,n) sssp_pairs.push_back({sssp[i],i});
	sort(all(sssp_pairs));

	vector<pair<string,ll>> ans;
	string s(n,'0');
	int i;
	for(i=0;i<n-1;++i) {
		s[sssp_pairs[i].se] = '1';
		ans.push_back({s, sssp_pairs[i+1].fi - sssp_pairs[i].fi });
		if (sssp_pairs[i+1].se == n-1) {
			break;
		}
	}

	cout<<sssp_pairs[i+1].fi<<' '<<ans.size()<<'\n';
	for(auto &it: ans) {
		cout<<it.fi<<' '<<it.se<<'\n';
	}
}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
