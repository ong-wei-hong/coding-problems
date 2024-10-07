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

int n,k,t;

void solve() {
	cin>>n>>t>>k;
	int left=1,right=n,order=k;

	while(right-left>=2) {
		int mid=(left+right)/2;
		cout<<"? "<<left<<' '<<mid<<'\n';
		cout.flush();
		int left_ones,left_zeros;
		cin>>left_ones;
		if(left_ones==-1) exit(0);
		left_zeros = (mid-left+1) - left_ones;

		if(left_zeros>=order) right=mid;
		else left=mid+1,order -= left_zeros;
	}

	if(right!=left) {
		cout<<"? "<<left<<' '<<left<<'\n';
		cout.flush();
		int a;
		cin>>a;
		if(a==-1) exit(0);
		if((order==1&&a==1)||(order==2&&a==0)) left=right;
	}

	cout<<"! "<<left<<'\n';
	cout.flush();
}

int main() {
//	freopen("loan.in", "r", stdin);
//	freopen("loan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
