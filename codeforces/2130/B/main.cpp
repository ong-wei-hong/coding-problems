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

int n,s,a;

void solve() {
	cin>>n>>s;
	int sum = 0,num_zero=0,num_one=0,num_two=0;
	while(n--) {
		cin>>a;
		sum += a;
		num_zero += (a == 0);
		num_one += (a == 1);
		num_two += (a == 2);
	}
	if (s < sum || s == sum + 1) {
		rep(_,0,num_zero) cout<<"0 ";
		rep(_,0,num_two) cout<<"2 ";
		rep(_,0,num_one) cout<<"1 ";
	} else {
		cout<<"-1";
	}
	cout<<'\n';
}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) {
		solve();
	}
}
