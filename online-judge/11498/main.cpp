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

int k,n,m,x,y;
bool a,b;

void solve() {
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    while(1) {
        cin>>k;
        if(!k) break;
        cin>>n>>m;
        forn(i,k) {
            cin>>x>>y;
            if(x==n||y==m) {
                cout<<"divisa\n";
                continue;
            }
            a=x>n,b=y>m;
            if(a&&b) cout<<"NE\n";
            else if((!a)&&b) cout<<"NO\n";
            else if(a&&(!b)) cout<<"SE\n";
            else cout<<"SO\n";
        }
    }
}
