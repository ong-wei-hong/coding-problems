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

int N,Q,l,r,v;
map<int,ll> m1,m2;

void solve() {
	cin>>N>>Q;
	while(N--) {
		cin>>l>>r>>v;
		m1[l]+=v,m1[r]-=v;
	}

	ll curr=0,s=0;
	int prev=-1;
	for(auto &it: m1) {
		s+=(it.first-prev)*curr+it.second;
		m2[it.first]=s;
		prev=it.first;

		curr+=it.second;
		it.second=curr;
	}

//	cout<<"m1\n";
//	for(auto &it: m1) cout<<it.first<<':'<<it.second<<'\n';
//	cout<<"m2\n";
//	for(auto &it: m2) cout<<it.first<<':'<<it.second<<'\n';

	while(Q--) {
		cin>>l>>r;
		--r;
		--l;

		ll s1,s2;

		auto it=m2.upper_bound(r);
		if(it==m2.begin()) s2=0;
		else {
			--it;
			s2=it->second;
			s2+=1LL*(r-(it->first))*m1[it->first];
		}

		it=m2.upper_bound(l);
		if(it==m2.begin()) s1=0;
		else {
			--it;
			s1=it->second;
			s1+=1LL*(l-(it->first))*m1[it->first];
		}

		cout<<s2-s1<<'\n';
	}
}

int main() {
	//freopen("wormsort.in", "r", stdin);
	//freopen("wormsort.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	solve();
}
