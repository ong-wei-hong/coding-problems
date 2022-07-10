#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

#define fi first
#define se second
#define pb push_back

int s;

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>s;
	cout<<s<<":\n";
	for(int i=2;i<=(s+1)/2;++i) {
		if(s%(2*i-1)==0||s%(2*i-1)==i) cout<<i<<','<<i-1<<'\n';	
		if(s%i==0) cout<<i<<','<<i<<'\n';
	}
}
