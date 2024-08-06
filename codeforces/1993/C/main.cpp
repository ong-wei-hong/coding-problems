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

int n,k;
map<int,int> m;

void solve() {
	cin>>n>>k;
	int maxi=0;
	m.clear();
	rep(_,0,n) {
		int a;
		cin>>a;
		maxi=max(maxi,a);
		++m[a%(2*k)];
		--m[(a+k)%(2*k)];
	}

	{
		int curr=0;
		for(auto &it: m) {
			curr+=(it.second);
			it.second=curr;
		}
	}

	//for(auto &it: m) cout<<it.first<<':'<<it.second<<'\n';

	for(auto it=m.find(maxi%(2*k));it!=m.end();++it) 
		if((it->second)-(m[(it->first+k)%(2*k)])==n) {
			cout<<maxi+(it->first)-(maxi%(2*k))<<'\n';
			return;
		}

	for(auto it: m) 
		if((it.second)-(m[(it.first+k)%(2*k)])==n) {
//			cout<<'b';
			cout<<((maxi+2*k-1)/2/k)*2*k+(it.first)<<'\n';
			return;
		}

	cout<<"-1\n";
}

int main() {
	//freopen("meetings.in", "r", stdin);
	//freopen("meetings.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}

