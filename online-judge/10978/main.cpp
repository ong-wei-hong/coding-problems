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

int n;
string s,t;

void solve() {
}

void file() {
    freopen("","r",stdin);
    freopen("","w",stdout);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(1) {
        cin>>n;
        if(!n) break;
        vector<string> v(n);
        vector<bool> b(n,0);
        int i=-1;
        forn(j,n) {
            cin>>s>>t;
            forn(k,t.length()) {
                i=(i+1)%n;
                while(b[i]) i=(i+1)%n;
            }
            b[i]=1;
            v[i]=s;
        }
        forn(j,n-1) cout<<v[j]<<' ';
        cout<<v[n-1]<<'\n';
    }
}