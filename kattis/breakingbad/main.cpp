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

int n,m;

void solve() {
}

void file() {
    freopen("","r",stdin);
    freopen("","w",stdout);
}

bool dfs(const vector<vi>& al,vi& b,int i) {
    if(b[i]) return 0;
    int c=0;
    for(auto j: al[i]) {
        if(b[j]&&c&&b[j]!=c) return 1;
        if(b[j]) c=b[j];
    }
    if(c<=1) b[i]=2;
    else b[i]=1;
    for(auto j: al[i]) if(dfs(al,b,j)) return 1;
    
    return 0;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    vector<string> v(n);
    unordered_map<string,int> ma;
    forn(i,n) cin>>v[i],ma.insert(mp(v[i],i));

    cin>>m;
    vector<vi> al(n,vi());
    forn(i,m) {
        string s,t;
        cin>>s>>t;
        int a=ma[s],b=ma[t];
        al[a].pb(b);
        al[b].pb(a);
    }

    vi b(n,0);
    forn(i,n) if(dfs(al,b,i)) {
        cout<<"impossible\n";
        return 0;
    }
    

    forn(i,n) if(b[i]==1) cout<<v[i]<<' ';
    cout<<'\n';
    forn(i,n) if(b[i]==2) cout<<v[i]<<' ';
    cout<<'\n';
}