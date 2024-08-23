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

constexpr int MAX_M=1e3;
int n;
bool m[MAX_M+1];
vector<pii> edges;

void solve() {
	cin>>n;
	memset(m,0,sizeof m);
	m[1]=1;

	edges.clear();
	for(int i=2;i<=n;++i) while(!m[i]) {
		int a=1,b=i,c;
		while(1) {
			cout<<"? "<<a<<' '<<b<<'\n';
			cout.flush();
			cin>>c;
	
			if(c==a) {
				m[b]=1;
				edges.push_back({a,b});
				break;
			}

			if(m[c]) a=c;
			else b=c;
		}
	}

	cout<<"!";
	for(auto &p: edges) cout<<' '<<p.fi<<' '<<p.se;
	cout<<'\n';
	cout.flush();
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

