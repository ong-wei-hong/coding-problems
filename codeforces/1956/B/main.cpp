#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi v;
void solve() {
	int n;
	cin>>n;
	v.resize(n);
	for(auto &i: v) cin>>i;
	sort(all(v));

	int a=0;
	rep(i,0,n-1) a+=(v[i]==v[i+1]);
	cout<<a<<'\n';
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	int t;
	cin>>t;
	while(t--) solve();
}
