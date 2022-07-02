#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int n,x,y;
bool u[32],b[32];
string s;

void solve() {
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    while(1) {
	    cin>>n;
	    if(n==0) break;
	    for(auto &i: u) i=0;
	    while(n--) {
		    cin>>s;
		    if(s=="SET") {
			    cin>>x;
			    u[x]=1;
			    b[x]=1;
		    }else if(s=="CLEAR") {
			    cin>>x;
			    u[x]=1;
			    b[x]=0;
		    }else if(s=="AND") {
			    cin>>x>>y;
			    u[x]=(u[x]&&!b[x])||(u[y]&&!b[y])||(u[y]&&u[x]);
			    b[x]&=b[y];
		    }else if(s=="OR") {
			    cin>>x>>y;
			    u[x]=(u[x]&&b[x])||(u[y]&&b[y])||(u[x]&&u[y]);
			    b[x]|=b[y];
		    }
	    }
	    forn(i,32) {
		    if(!u[32-i-1]) {
			    cout<<'?';
			    continue;
		    }
		    if(b[32-i-1]) {
			    cout<<1;
			    continue;
		    }
		    cout<<0;
	    }
	    cout<<'\n';
    }
}
	    		
