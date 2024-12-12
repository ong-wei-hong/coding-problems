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
vi p;
vi last_node;
list<int> active;

int query(int a, int b) {
	cout<<"? "<<a<<' '<<b<<'\n';
	cout.flush();
	int r;
	cin>>r;
	if(r == -1) exit(0);
	return r;
}

void solve() {
	cin>>n;
	p.resize(n);
	active.clear();
	last_node.clear();

	p[1] = 0;
	int m=2;
	for(;m<n;++m) {
		int r = query(1,m);
		if(r==0) break;
		p[m]=0;
	}

	p[m]=1;
	rep(i,1,m) active.push_back(i);
	auto curr_it = active.begin();
	if(active.size()>1) ++curr_it;

	last_node.resize(m);
	rep(i,2,m) last_node[i]=i;
	last_node[1] = m;

	for(int i=m+1;i<n;) {
		int r = query(i,*curr_it);
		if (r==0) {
			p[i]=last_node[*curr_it];
			last_node[*curr_it]=i;
			++curr_it;
			++i;
			if(curr_it==active.end()) curr_it=active.begin();
		} else if(r==1) {
			auto next_it=curr_it;
			++next_it;
			if(next_it==active.end()) next_it=active.begin();
			active.erase(curr_it);
			curr_it = next_it;
		}
	}

	cout<<'!';;
	rep(i,1,n) cout<<' '<<p[i];
	cout<<'\n';
	cout.flush();
}

int main() {
//	freopen("revegetate.in", "r", stdin);
//	freopen("revegetate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
