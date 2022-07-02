#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int n,a,b;
bool l{1};

void solve() {
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    while(1) {
	    cin>>n;
	    if(n==0) break;
	    a=b=0;
	    l=1;
	    while(n) {
		    int c=n&(-n);
		    n-=c;
		    if(l) a+=c;
		    else b+=c;
		    l=!l;
	    }
	    cout<<a<<' '<<b<<'\n';
    }
}
