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
string s,ans;
std::priority_queue<pair<int,char>> pq;
map<char,int> m;

void solve() {
	cin>>n>>s;
	m.clear();
	for(auto c: s) ++m[c];
	for(auto &p: m) pq.push({p.se,p.fi});

	auto [i,c] = pq.top();
	ans="";
	ans+=c;
	pq.pop();
	if(i!=1) pq.push({i-1,c});

	while(pq.size()) {
		auto [i,c] = pq.top();
		pq.pop();

		if(c==ans.back()&&pq.size()) {
			auto [i1,c1] = pq.top();
			pq.pop();
			ans+=c1;
			if(i1!=1) pq.push({i1-1,c1});
		} else {
			ans+=c;
			--i;
		}

		if(i) pq.push({i,c});
	}

	cout<<ans<<'\n';
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
