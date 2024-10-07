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

int n,m,q,a,b;
set<int> teachers;

void solve() {
	cin>>n>>m>>q;
	teachers.clear();
	while(m--) {
		cin>>b;
		teachers.insert(b);
	}
	while(q--) {
		cin>>a;
		auto it=teachers.upper_bound(a);
		if(it==teachers.end()) {
			cout<<n-(*teachers.rbegin())<<'\n';
			continue;
		}
		if(it==teachers.begin()) {
			cout<<(*teachers.begin()) - 1<<'\n';
			continue;
		}

		int r=*it,l;
		--it;
		l=*it;
		cout<<(r-l)/2<<'\n';
	}
}

int main() {
//	freopen("angry.in", "r", stdin);
//	freopen("angry.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
