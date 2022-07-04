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

int t,a,b,c,d,e;

void solve() {
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin>>t;
    while(t--) {
        cin>>a>>b>>c>>d>>e;
        if(a+1==b&&b+1==c&&c+1==d&&d+1==e) cout<<"Y\n";
        else cout<<"N\n";
    }
}
