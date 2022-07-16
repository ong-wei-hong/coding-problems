#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define fi first
#define se second
#define pb push_back
#define mp make_pair

int t,n,m;

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

int f(vi& s,int i) {
	if(s[i]==i) return i;
	return (s[i]=f(s,s[i]));
}

void u(vi& s,vi& r,int i,int j) {
	int a=f(s,i),b=f(s,j);
	if(a==b) return;
	if(r[a]<r[b]) s[a]=b;
	else s[b]=a;
	if(r[a]==r[b]) ++r[a];
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>m;
		
		vi s(n+1);
		vi r(n+1,0);
		forn(i,n+1) s[i]=i;

		vector<pair<int,ii>> e(m,mp(0,mp(0,0)));
		for(auto& i: e) cin>>i.se.fi>>i.se.se>>i.fi;
		sort(rall(e));

		ll x=0;
		for(auto& i: e) {
			int a=i.se.fi,b=i.se.se;
			if(f(s,a)!=f(s,b)) u(s,r,a,b);
			else x+=i.fi;
		}
		cout<<x<<'\n';
	}
	cin>>t;
}

