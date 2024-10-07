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

pair<ll,ll> startCoords, endCoords;
int n;
string s;

void solve() {
	cin>>startCoords.fi>>startCoords.se>>endCoords.fi>>endCoords.se;
	cin>>n>>s;
	pair<ll,ll> accuCoords {0, 0};

	for(auto dir: s) {
		switch(dir) {
			case 'U': ++accuCoords.se; break;
			case 'D': --accuCoords.se; break;
			case 'L': --accuCoords.fi; break;
			case 'R': ++accuCoords.fi; break;
		}
	}

	ll lb=1,ub=2e15,ans=-1;
	while(lb<=ub) {
		ll mid=(lb+ub)/2,numCycles=mid/s.size();
		pair<ll,ll> currCoords {
			startCoords.fi + numCycles * accuCoords.fi,
			startCoords.se + numCycles * accuCoords.se
		};

		for(ll i=0;numCycles*s.size()+i<mid;++i) {
			switch(s[i]) {
				case 'U': ++currCoords.se; break;
				case 'D': --currCoords.se; break;
				case 'L': --currCoords.fi; break;
				case 'R': ++currCoords.fi; break;
			}
		}

		ll dist = abs(currCoords.fi-endCoords.fi) + abs(currCoords.se - endCoords.se);
		if(dist <= mid) ans=mid,ub=mid-1;
		else lb=mid+1;
	}

	cout<<ans<<'\n';
}

int main() {
//	freopen("loan.in", "r", stdin);
//	freopen("loan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
