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

ll N,M;
map<int,int> m;
vector<pair<ll,ll>> A;

void solve() {
	cin>>N>>M;
	m.clear();
	while(N--) {
		int a;
		cin>>a;
		++m[a];
	}

	A.resize(m.size()); 
	{
		int i=0;
		for(auto &p: m) A[i++]=p;
	}

	ll ans=0;
	for(auto &p: A) ans=max(ans,min(M/p.first,p.second)*p.first);

	rep(i,0,A.size()-1) if(A[i].first+1==A[i+1].first) {
		ll x=A[i].first,
		   a=min(A[i].second,M/x),
		   b=min(A[i+1].second,(M-a*x)/(x+1)),
		   M_left=M-a*x-b*(x+1),
		   diff=min(a,min(M_left,A[i+1].second-b));

		ans=max(ans,a*x+b*(x+1)+diff);
	}

	cout<<ans<<'\n';
}

int main() {
	//freopen("lifeguards.in", "r", stdin);
	//freopen("lifeguards.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
