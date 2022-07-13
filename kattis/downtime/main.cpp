#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

#define fi first
#define se second
#define pb push_back
#define mp make_pair

int n,k;
ll t[100001];

void solve() {
}

void file() {
    freopen("","r",stdin);
    freopen("","w",stdout);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    int a;
    while(n--) cin>>a,++t[a];
    ll r=0,m=0;
    for(int i=0;i<1000;++i) r+=t[i];
    m=max(m,r);
    for(int i=1000;i<=100001;++i) r+=t[i]-t[i-1000],m=max(m,r);
    cout<<(m+k-1)/k<<'\n';
}