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

int b,s,l,r;

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	while(1) {
		cin>>s>>b;
		if(!b&&!s) break;
		vii v(s,make_pair(0,0));
		forn(i,s) v[i].fi=i-1,v[i].se=i+1;
		while(b--) {
			cin>>l>>r;
			--l,--r;
			if(v[l].fi==-1) cout<<"* ";
			else cout<<v[l].fi+1<<' ';
			if(v[r].se==s) cout<<"*\n";
			else cout<<v[r].se+1<<'\n';

			if(v[l].fi!=-1) v[v[l].fi].se=v[r].se;
			if(v[r].se!=s) v[v[r].se].fi=v[l].fi;
		}
		cout<<"-\n";
	}
}
