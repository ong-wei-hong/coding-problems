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

int n,s1,s2;
vector<vector<int>> al1,al2;
vi bp1,bp2;
set<pii> el2,vis;

bool isbp(const vector<vi> &al, vi &bp, int curr_v, int colour) {
	if (bp[curr_v] != -1) return bp[curr_v] == colour;

	bp[curr_v] = colour;

	for(auto v: al[curr_v]) {
		if(!isbp(al,bp,v,1-colour)) return false;
	}

	return true;
}

void populate(vector<vi> &al, bool pop_el2) {
	int m;
 	cin>>m;

	while(m--) {
		int v,u;
		cin>>v>>u;
		--v,--u;
		al[v].push_back(u);
		al[u].push_back(v);

		if(pop_el2) {
			el2.insert({min(u,v),max(u,v)});
		}
	}
}

void solve() {
	cin>>n>>s1>>s2;
	al1.assign(n,vi());
	al2.assign(n,vi());
	el2.clear();
	populate(al1,false);
	populate(al2,true);

	--s1,--s2;
	bp1.assign(n,-1);
	bp2.assign(n,-1);
	bool isbp1=isbp(al1,bp1,s1,0),isbp2=isbp(al2,bp2,s2,0),valid=0;
	rep(v,0,n) {
		for(auto u: al1[v]) if(el2.count({min(v,u),max(v,u)})) {
			if(!isbp1 || !isbp2 || (bp1[v] == bp2[v])) {
				valid=1;
				break;
			}
		}

		if (valid) break;
	}

	if(!valid) {
		cout<<"-1\n";
		return;
	}

	vis.clear();
	std::priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
	pq.push({0,{s1,s2}});
	while(!pq.empty()) {
		auto p = pq.top(); pq.pop();
		int cost = p.fi, v1=p.se.fi, v2=p.se.se;

		for(auto u1: al1[v1]) for(auto u2: al2[v2]) {
			if (v1 == v2 && u1 == u2) {
				cout<<cost<<'\n';
				return;
			}
			
			if (vis.count({u1,u2})) continue;

			int new_cost = cost + abs(u1 - u2);
			pq.push({new_cost, {u1, u2}});
			vis.insert({u1,u2});
		}
	}
}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
