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

struct p {
	pii w;
	int idx;
};

int n;
vector<pii> v;
map<int,pii> m;
vi ans;

void solve() {
	cin>>n;
	v.resize(n);
	for(auto &p: v) {
		cin>>p.first>>p.second;
		if(p.first<p.second) swap(p.first,p.second);
	}
	//rep(i,0,n) cout<<v[i].w.first<<','<<v[i].w.second<<" \n"[i==n-1];

	m.clear();
	rep(i,0,n) {
		auto it=m.find(v[i].first);
		if(it==m.end()) {
			m[v[i].first]={INT_MAX,-1};
			it=m.find(v[i].first);
		}

		if(v[i].second<(it->second).first) it->second={v[i].second,i+1};
	}

	{
		int prev_min=INT_MAX,prev_idx=-1;
		for(auto &p: m) {
			if(p.second.first<prev_min) 
				prev_min=p.second.first,prev_idx=p.second.second;

			p.second={prev_min,prev_idx};
		}
	}

	for(auto &p: v) {
		auto it=m.find(p.first);
		if(it==m.begin()) {
			cout<<"-1 ";
			continue;
		}
		--it;
		cout<<(((it->second).first<p.second)?(it->second).second:-1)<<' ';
	}

	cout<<'\n';
}

int main() {
	//freopen("split.in", "r", stdin);
	//freopen("split.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	int t;
	cin>>t;
	while(t--) solve();
}
