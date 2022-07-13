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

int n,a;

void solve() {
}

void file() {
    freopen("","r",stdin);
    freopen("","w",stdout);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    vi v;
    while(n--) {
        cin>>a;
        if(v.empty()||v[v.size()-1]<a) v.pb(a);
    }
    cout<<v.size()<<'\n';
    for(auto i: v) cout<<i<<' ';
    cout<<'\n';
}