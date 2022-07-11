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

int n,c,p;

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	while(1) {
		cin>>n;
		if(!n) break;
		vi v(n,0);
		bool va=1;
		forn(i,n) {
			cin>>c>>p;
			if((i+p>=0)&&(i+p<n)&&(v[i+p]==0)) v[i+p]=c;
			else va=0;
		}
		if(va) for(auto i: v) if(i==v[0]) cout<<i; else cout<<' '<<i;
		else cout<<-1;
		cout<<'\n';
	}
}
