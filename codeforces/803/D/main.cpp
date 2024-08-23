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
string s;
vi v;

void solve() {
	

}

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin>>n;
	cin.ignore(256,'\n');
	getline(cin,s);

	v.push_back(0);
	for(auto c: s) {
		++v.back();
		if(c==' '||c=='-') v.push_back(0);
	}

	ll lb=1,ub=1e6,ans;
	while(lb<=ub) {
		ll mid=(lb+ub)/2;

		bool valid=1;
		int k=0,curr=0;
		for(auto i: v) {
			if(i>mid) {
				valid=0;
				break;
			}
			if(curr+i>mid) ++k,curr=0;
			curr+=i;
		}
		k+=(curr>0);

		if(valid&&k<=n) {
			ans=mid;
			ub=mid-1;
		} else lb=mid+1;
	}

	cout<<ans<<'\n';
}
