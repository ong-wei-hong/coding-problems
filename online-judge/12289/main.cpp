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

int t;
string s;
const string one="one",two="two";

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
    cin>>t;
    while(t--) {
        cin>>s;
        if(s.length()==5) cout<<3<<'\n';
        else {
            int i=0,j=0;
            forn(k,3) i+=(s[k]==one[k]),j+=(s[k]==two[k]);
            if(i>=2) cout<<1<<'\n';
            if(j>=2) cout<<2<<'\n';
        }
    }
}
