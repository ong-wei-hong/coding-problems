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

int t,n,x,y,h,l;

void solve() {
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin>>t;
    forn(i,t) {
        cin>>n;
        h=l=0;
        cin>>x;
        forn(i,n-1) {
            cin>>y;
            h+=(y>x);
            l+=(y<x);
            x=y;
        }
        cout<<"Case "<<i+1<<": "<<h<<' '<<l<<'\n';
    }
}