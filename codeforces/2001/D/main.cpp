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
vi v,ans;
map<int,int> int_to_last_pos;
set<int> taken,last_pos;
map<int,queue<int>> dict;

void solve() {
	cin>>n;
	v.resize(n);
	for(auto &i: v) cin>>i;

	int_to_last_pos.clear();
	taken.clear();
	last_pos.clear();
	dict.clear();
	ans.clear();

	rep(i,0,n) int_to_last_pos[v[i]] = i;
	for(auto &p: int_to_last_pos) last_pos.insert(p.se);

	ans.clear();
	int i=-1,j=-1,m=last_pos.size();
	rep(pos,0,m) {
		{
			int k=*last_pos.begin();
//			cout<<"pos: "<<pos<<", k:"<<k;
			while(j<k) {
				++j;
				if(taken.count(v[j])) continue;
				auto it=dict.find(v[j]);
				if(it==dict.end()) {
					dict[v[j]]=queue<int>();
					it=dict.find(v[j]);
				}
				(it->se).push(j);
			}
		}

//		cout<<",dict: ";
//		for(auto &p: dict) cout<<p.fi<<':'<<p.se.size()<<' ';

		int removeIdx,takenN;
		if(pos&1) {
			auto it=dict.begin();
			removeIdx=it->se.front();
			takenN=it->fi;

		} else {
			auto it = dict.rbegin();
			removeIdx=it->se.front();
			takenN=it->fi;
		}

		ans.push_back(takenN);
		taken.insert(takenN);
		last_pos.erase(int_to_last_pos[takenN]);
		dict.erase(takenN);
		while(i<removeIdx) {
			++i;
			if(taken.count(v[i])) continue;
			auto it=dict.find(v[i]);
			(it->se).pop();
			if((it->se).empty()) dict.erase(it);
		}
//	cout<<'\n';

	}

	cout<<ans.size()<<'\n';
	for(auto i: ans) cout<<i<<' ';
	cout<<'\n';
}

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}

