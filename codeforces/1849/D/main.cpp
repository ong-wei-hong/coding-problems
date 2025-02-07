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
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vi a;

void solve() {
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;

	int cnt=1,carry=0,used=0;
	rep(i,0,n) {
		if (a[i] == 0) {
			if (carry) {
				carry=0,used=0;
				cnt += (i < n-1);
			} else if (i < n-1 && a[i+1]) {
				carry=0,used=1;
			} else {
				cnt += (i < n-1);
				carry=0,used=0;
			}
		} else if (a[i] == 1) {
			if (used) {
				if(i < n-1 && a[i+1]) {
					carry=0,used=1;
				} else {
					cnt += (i < n-1);
					carry=0,used=0;
				}
			} else {
				carry=1,used=0;
			}
		} else if (a[i] == 2) {
			carry=1,used=0;
		}
	}

	cout<<cnt<<'\n';
}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
