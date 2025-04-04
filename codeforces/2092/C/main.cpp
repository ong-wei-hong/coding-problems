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
ll a;

void solve() {
	int numOdd,numEven;
	ll sum,mx;
	numOdd=numEven=sum=mx=0;

	cin>>n;
	while(n--) {
		cin>>a;
		mx = max(mx,a);

		numOdd += (a & 1);
		numEven += !(a & 1);
		sum += a;
	}

	if(numOdd == 0 || numEven == 0) {
		cout<<mx<<'\n';
	} else {
		cout<<sum - numOdd + 1<<'\n';
	}
}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
