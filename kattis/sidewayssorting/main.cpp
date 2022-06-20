#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int r,c;
char ch;

void solve() {
}

bool compare(const string& s,const string& t) {
    forn(i,s.size()) if(tolower(s[i])!=tolower(t[i])) return tolower(s[i])<tolower(t[i]);
    return false;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	//cin>>t;
	//while(t--) solve();
    while(1) {
        cin>>r>>c;
        if(!r&&!c) return 0;
        vector<string> s(c);
        for(auto &i: s) i="";
        forn(i,r) for(auto &j: s) cin>>ch,j+=ch;
        sort(all(s),compare);
        forn(i,r) {
            for(const auto &j: s) cout<<j[i];
            cout<<'\n';
        }
        cout<<'\n';
    }
}
