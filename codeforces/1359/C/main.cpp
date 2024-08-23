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

int c,h,t;

void solve() {
	cin>>h>>c>>t;
	if(h+c>=2*t) {
		cout<<"2\n";
		return;
	}

	double cups=floor((1.0*(t-h))/(h+c-2*t));
	if(abs(((cups+2)*h+(cups+1)*c)/(2*cups+3)-t) < abs(((cups+1)*h+cups*c)/(2*cups+1) - t)) {
		cout<<2*(ll)cups+3<<'\n';
	} else {
		cout<<2*(ll)cups+1<<'\n';
	}



}

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}

