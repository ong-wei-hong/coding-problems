#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()

int t,x;
string s;
const int a[5]{600,60,0,10,1},g[16]{0,70,140,210,280,350,601,671,741,811,881,951,1202,1272,1342,1412};

void solve() {
	cin>>s>>x;
	int m=0,n,ans=0;
	forn(i,5) m+=(int)(s[i]-'0')*a[i];
	n=m;
	do {
		for(int i:g) if(i==n) {
			++ans;
			break;
		}
		n=(n+x)%1440;
	} while(n!=m);
	cout<<ans<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--) solve();
}
