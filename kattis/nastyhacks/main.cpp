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

int n,r,e,c;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
    cin>>n;
    while(n--) {
        cin>>r>>e>>c;
        int x=e-c;
        if(r>x) cout<<"do not advertise\n";
        else if(r==x) cout<<"does not matter\n";
        else cout<<"advertise\n";
    }
}
