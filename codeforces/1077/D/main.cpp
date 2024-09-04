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

int n,k,a;
map<int,int> s;
vi ans;

int main() {
//	freopen("cardgame.in", "r", stdin);
//	freopen("cardgame.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin>>n>>k;
	rep(_,0,n) {
		cin>>a;
		++s[a];
	}

	int lb=1,ub=2e5;
	while(lb<=ub) {
		int mid=(lb+ub)/2;
		vi curr;
		for(auto &p: s) {
			if(curr.size()>=k) break;
			rep(_,0,p.se/mid) curr.push_back(p.fi);
		}


		while(curr.size()>k) curr.pop_back();

		if(curr.size()==k) {
			lb=mid+1;
			ans=curr;
		} else {
			ub=mid-1;
		}
	}

	for(auto i: ans) cout<<i<<' ';
	cout<<'\n';
}

