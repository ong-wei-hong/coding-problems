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

bool a,b,c;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
    while(cin>>a>>b>>c) {
        if(a!=b&&b==c) cout<<"A\n";
        else if(b!=c&&a==c) cout<<"B\n";
        else if(c!=a&&a==b) cout<<"C\n";
        else cout<<"*\n";
    }
}
