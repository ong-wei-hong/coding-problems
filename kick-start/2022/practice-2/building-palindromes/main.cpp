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

int t,n,q,l,r;
string s;

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	forn(i,t) {	
		cin>>n>>q>>s;
		vector<vi> vvi(26,vi(n+1));
		forn(j,n) ++vvi[s[j]-'A'][j+1];
		forn(j,26) forn(k,n) vvi[j][k+1] += vvi[j][k];
		int ans=0;
		forn(j,q) {
			cin>>l>>r;
			bool o=0,v=1;
			forn(k,26) 
				if((vvi[k][r]-vvi[k][l-1])&1)
					if(o) {
						v=0;
						break;
					} else o=1;
			ans+=v;
		}
		cout<<"Case #"<<i+1<<": "<<ans<<'\n';
	}
}
			
