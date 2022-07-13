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

string s;

void solve() {
}

void file() {
    freopen("","r",stdin);
    freopen("","w",stdout);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>s) {
        bool l=0;
        int m=0,i=0;
        for(auto c: s) {
            switch(c) {
                case '.': ++i; break;
                case 'X':
                    --i;
                    if(!l) l=1;
                    else i/=2;
                    m=max(m,i);
                    i=0;
            }
        }
        m=max(m,i-1);
        cout<<m<<'\n';
    }
}