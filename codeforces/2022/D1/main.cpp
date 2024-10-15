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

int n;
vi v;

int ask(int i, int j) {
	cout<<"? "<<++i<<' '<<++j<<endl;
	int k;
	cin>>k;
	if (k == -1) exit(0);
	return k;
}

void ans(int k) {
	cout<<"! "<<++k<<endl;
}

void solve() {
	cin>>n;
	v.resize(n);

	int a=ask(0,1),b=ask(1,0);
	if(a!=b) {
		int c=ask(0,2),d=ask(2,0);
		if(c==d) ans(1);
		else ans(0);
		return;
	}

	v[0]=1;
	v[1]=(!a)^v[0];
	
	a=ask(0,n-1),b=ask(n-1,0);
	if(a!=b) {
		ans(n-1);
		return;
	}

	rep(i,1,n-1) {
		a=ask(i,i+1);
		v[i+1] = (!a) ^ v[i];
	}

//	for(auto &i: v) cout<<i<<' ';
//	cout<<'\n';

	int lb=2,ub=n-1;
	while(lb<ub) {
		int mid=(lb+ub)/2;
		a=ask(0,mid),b=(!a)^v[0];
//		cout<<mid<<' '<<(b==v[mid])<<'\n';
		if(b==v[mid]) lb=mid+1;
		else ub=mid;
	}
	ans(ub-1);
}

int main() {
//	freopen("loan.in", "r", stdin);
//	freopen("loan.out", "w", stdout);
//	cin.tie(0)->sync_with_stdio(0);
//	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
