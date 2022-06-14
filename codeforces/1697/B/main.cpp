#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()

int n,q,x,y;
ll p[200001];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
    cin>>n>>q;
    forn(i,n) cin>>p[i+1];
    sort(p,p+n+1);
    forn(i,n) p[i+1]+=p[i];
    while(q--) {
        cin>>x>>y;
        cout<<p[n-x+y]-p[n-x]<<'\n';
    }

	return 0;
}
