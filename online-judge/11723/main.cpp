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

int n,r,i;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
    while(1) {
        cin>>n>>r;
        if(n==0&&r==0) break;
        cout<<"Case "<<(++i)<<": ";
        int x=n/r-((n%r)==0);
        if(x>26) cout<<"impossible\n";
        else cout<<x<<'\n';
    }
}

