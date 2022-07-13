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

int n,m,r,a,b;

void solve() {
}

void file() {
    freopen("","r",stdin);
    freopen("","w",stdout);
}

int f(vi& ufds,int i) {
    if(ufds[i]==i) return i;
    return (ufds[i]=f(ufds,ufds[i]));
}

bool u(vi& ufds,vi& rank,int a,int b) { 
    int x=f(ufds,a),y=f(ufds,b);   
    if(x==y) return 0;
    if(rank[x]>rank[y]) ufds[y]=x;
    else ufds[x]=y;
    if(rank[x]==rank[y]) ++rank[y];
    return 1;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    while(n--) {
        cin>>m>>r;
        vi ufds(m);
        vi rank(m,0);
        forn(i,m) ufds[i]=i;
        int ans=m-1;
        while(r--) {
            cin>>a>>b;
            ans-=u(ufds,rank,a,b);
        }
        cout<<ans<<'\n';
    }
}