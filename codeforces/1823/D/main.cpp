#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define aml(x) begin(x), end(x)
#define raml(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define LSB(x) (x) & (-x)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_K=20;
int n,k,x[MAX_K],c[MAX_K];

void solve() {
	cin>>n>>k;
	rep(i,0,k) cin>>x[i];
	rep(i,0,k) cin>>c[i];
	
	if (c[0] > x[0]) {
		cout<<"NO\n";
		return;
	}

	rep(i,1,k) if(c[i]-c[i-1] > x[i]-x[i-1]) {
		cout<<"NO\n";
		return;
	}

	cout<<"YES\n";
	int last = 0;
	{
		rep(_,0,c[0]-3) cout<<'d';
		rep(_,0,x[0]-c[0]+3) {
			cout<<(char)('a'+last);
			last = (last+1)%3;
		}
	}

	rep(i,1,k) {
		rep(_,0,c[i]-c[i-1]) cout<<(char)('d'+i);
		rep(_,0,x[i]-x[i-1]-c[i]+c[i-1]) {
			cout<<(char)('a'+last);
			last = (last+1)%3;
		}
	}
	cout<<'\n';
}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
//	cin.tie(0)->sync_with_stdio(0);
//	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
