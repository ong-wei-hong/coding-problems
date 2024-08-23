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

const int MAX_N=1e7;
int sieve[MAX_N+1],n,a;

void solve() {
	cin>>n;
	int res=0;
	while(n--) {
		cin>>a;
		res^=sieve[a];
	}
	if(res) cout<<"Alice\n";
	else cout<<"Bob\n";
}

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	sieve[0]=0;
	sieve[1]=1;
	for(int idx=2,i=3;i<=MAX_N;i+=2) 
		if(sieve[i]==0) {
			for(int j=i;j<=MAX_N;j+=i) if((j&1)&&sieve[j]==0) sieve[j]=idx;
			++idx;
		}

	int t;
	cin>>t;
	while(t--) solve();
}

