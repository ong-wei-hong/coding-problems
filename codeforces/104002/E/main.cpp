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

void solve() {
}

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin>>n;
	v.resize(n);
	for(auto &i: v) cin>>i;

	ll ans=0;
	std::priority_queue<int> pq;
	for(int i=n-2;i>=0;i-=2) {
		int curr=v[i];
		pq.push(v[i+1]);
		if(pq.top()>curr) {
			pq.push(curr);
			curr=pq.top();
			pq.pop();
		}
		ans+=curr;
	}
	cout<<ans<<'\n';
}

