#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int n,m,r,a[1000],b[1000];

void solve() {
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    //cin>>t;
    //while(t--) solve();
    while(cin>>n) {
	    cin>>m;
	    vector<vii> t(m+1);
	    forn(i,n) {
		    cin>>r;
		    forn(j,r) cin>>a[j];
		    forn(j,r) cin>>b[j];
		    forn(j,r) t[a[j]].emplace_back(i+1,b[j]);
	    }
	    cout<<m<<' '<<n<<'\n';
	    forn(i,m) {
		    cout<<t[i+1].size();
		    forn(j,t[i+1].size()) cout<<' '<<t[i+1][j].first;
		    cout<<'\n';
		    if(t[i+1].size()) cout<<t[i+1][0].second;
		    forn(j,t[i+1].size()-1) cout<<' '<<t[i+1][j+1].second;
		    cout<<'\n';
	    }
    }
}
