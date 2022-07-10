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

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	cin.ignore(256,'\n');
	while(t--) {
		int p,c,a=0;
		cin>>p;
		for(cin>>c;c;cin>>c) {
			a+=max(0,c-2*p);
			p=c;
		}
		cout<<a<<'\n';
	}
}
