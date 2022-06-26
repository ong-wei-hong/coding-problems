#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int t,n,i,j;
char c;

void solve() {
	cin>>n;
	vi v=vi(n+1);
	forn(k,n+1) v[k]=k;
	while(true) {
		cin>>c;
		switch(c) {
			case 'O': return;
			case 'E':{
				cin>>i;
				ll d=0L;
				while(v[i]!=i) {
					d+=abs(i-v[i])%1000;
					i=v[i];
				}
				cout<<d<<'\n';
				break;
			}
			case 'I':
				cin>>i>>j;
				v[i]=j;
				break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--) solve();
}
