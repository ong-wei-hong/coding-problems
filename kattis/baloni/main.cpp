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

int n,h[1000001];

void solve() {
}

void file() {
    freopen("","r",stdin);
    freopen("","w",stdout);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    int ans=0;
    while(n--) {
        int a;
        cin>>a;
        if(h[a]) --h[a],++h[a-1];
        else ++h[a-1],++ans;
    }
    cout<<ans<<'\n';
}