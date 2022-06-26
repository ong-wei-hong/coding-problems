#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int n,m,a[5000001],ans,b[5000001];

void solve() {
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    //cin>>t;
    //while(t--) solve();
    cin>>n;
    int c=1;
    while(n--) {
        cin>>m;
        vi v(m);
        forn(i,m) cin>>v[i];
        unordered_map<int,int> map{};
        forn(i,m) if(a[v[i]]) {
            auto it=map.find(a[v[i]]);
            if(it==map.end()) map[a[v[i]]]=1;
            else ++(it->second);
        }
        if(map.empty()) {
            ++ans;
            forn(i,m) a[v[i]]=c;
            b[c]=m;
            ++c;
            continue;
        }
        bool valid{true};
        for(auto it=map.begin();it!=map.end();++it) 
            if((it->second)!=b[it->first]) {
                valid=false;
                break;
            }
        if(!valid) continue;
        ++ans;
        int d=map.begin()->first;
        forn(i,m) a[v[i]]=d;
        b[d]=m;
    }
    cout<<ans<<'\n';
}
