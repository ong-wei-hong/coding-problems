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

int n,q;
vi p,inv_p,diffA;
string s;
set<int> bad_indices;

void solve() {
	cin>>n>>q;
	p.resize(n);
	inv_p.resize(n);

	rep(i,0,n) {
		cin>>p[i];
		--p[i];
		inv_p[p[i]] = i;
	}

	diffA.assign(n,0);
	rep(i,0,n) {
		++diffA[min(i,inv_p[i])];
		--diffA[max(i,inv_p[i])];
	}
	rep(i,1,n) diffA[i] += diffA[i-1];

	cin>>s;
	bad_indices.clear();
	rep(i,0,n-1) if(s[i]=='L'&&s[i+1]=='R'&&diffA[i]!=0) bad_indices.insert(i);

	while(q--) {
		int x;
		cin>>x;
		--x;

		s[x] = (s[x] == 'R' ? s[x] = 'L' : s[x] = 'R');

		if(s[x-1] == 'L' && s[x] == 'R' && diffA[x-1] != 0) {
			bad_indices.insert(x-1);
		} else {
			bad_indices.erase(x-1);
		}

		if(s[x] == 'L' && s[x+1] == 'R' && diffA[x] != 0) {
			bad_indices.insert(x);
		} else {
			bad_indices.erase(x);
		}

		if(bad_indices.size()) {
			cout<<"NO\n";
		} else {
			cout<<"YES\n";
		}
	}
}



int main() {
//	freopen("moocast.in", "r", stdin);
//	freopen("moocast.out", "w", stdout);
//	cin.tie(0)->sync_with_stdio(0);
//	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
