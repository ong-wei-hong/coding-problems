#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int a[5];

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	//cin>>t;
	//while(t--) solve();
    forn(i,5) cin>>a[i];
    while(1) {
        bool s{1};
        forn(i,4) if(a[i]>a[i+1]) {
            s=0;
            swap(a[i],a[i+1]);
            forn(i,5) cout<<a[i]<<' ';
            cout<<'\n';
        }
        if(s) return 0;
    }
}
