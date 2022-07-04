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

ll a,b;
int t,n,m;
string s;

void solve() {
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin>>t;
    cin.ignore(256,'\n');
    while(t--) {
        getline(cin,s);
        stringstream ss(s);
        a=b=0;
        while(ss>>n) a=a*10+n;
        getline(cin,s);
        stringstream tt(s);
        while(tt>>m) b=b*10+m;
        a+=b;
        s=to_string(a);
        cout<<s[0];
        forn(i,s.length()-1) cout<<' '<<s[i+1];
        cout<<'\n';
    }
}
    
