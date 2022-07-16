#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()
#define LSB(S) ((S)&-(S))

#define fi first
#define se second
#define pb push_back

void solve() {
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    vi f;
    int n;
    while(cin>>n) f.pb(n);

    vi ft;
    int m = (int) f.size() - 1;
    ft.assign(m+1,0);
    for(int i=1;i<=m;++i) {
	    ft[i]+=f[i];
	    if(i + LSB(i) <= m) ft[i+LSB(i)]+=ft[i];
    }
    for(auto i: ft) cout<<i<<' ';
    cout<<'\n';
}
