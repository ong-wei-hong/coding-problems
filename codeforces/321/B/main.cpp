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

int n,m,ans,strength;
vi atk,def;
multiset<int> ms;
string pos;

void f(bool noDefense) {
	int prefix1=0,prefix2=0,i=0,cnt=0;
	auto it=ms.rbegin();

	{
		auto it2=ms.begin();

		for(int k=0;it2!=ms.end()&&k<atk.size();++k) {
			while(it2!=ms.end()&&(*it2)<atk[k]) ++it2;
			if(it2==ms.end()) break;
			++cnt;
			++it2;
		}
	}


	for(int k=0;i<atk.size()&&it!=ms.rend()&&k<cnt;++i,++it,++k) {
		prefix1+=atk[i];
		prefix2+=*it;
		ans=max(ans,prefix2-prefix1);
	}

	if(noDefense&&cnt==atk.size()) {
		for(;it!=ms.rend();++it) prefix2+=*it;
		ans=max(ans,prefix2-prefix1);
	}
}

void solve() {
	cin>>n>>m;
	rep(_,0,n) {
		cin>>pos>>strength;
		if(pos=="ATK") atk.push_back(strength);
		if(pos=="DEF") def.push_back(strength);
	}

	rep(_,0,m) {
		cin>>strength;
		ms.insert(strength);
	}

	sort(all(atk));
	f(false);

	for(auto i: def) {
		auto it=ms.upper_bound(i);
		if(it==ms.end()) {
			cout<<ans<<'\n';
			return;
		}
		ms.erase(it);
	}

	f(true);

	cout<<ans<<'\n';
}

int main() {
//	freopen("berries.in", "r", stdin);
//	freopen("berries.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
