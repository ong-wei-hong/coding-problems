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

int t,s,p;

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
	cout<<fixed<<setprecision(2);
	while(t--) {
		cin>>s>>p;
		vii ps(p,mp(0,0));
		for(auto& i: ps) cin>>i.fi>>i.se;

		vector<pair<double,ii>> e;
		forn(i,p) for(int j=i+1;j<p;++j)
			e.pb(mp(sqrt(pow(ps[i].fi-ps[j].fi,2)+pow(ps[i].se-ps[j].se,2)),mp(i,j)));
		sort(all(e));

		vi ds(p);
		vi r(p,0);
		forn(i,p) ds[i]=i;
		vector<double> v;

		for(auto& i: e) {
			int a=i.se.fi,b=i.se.se;
			if(f(ds,a)!=f(ds,b)) v.pb(i.fi),u(ds,r,a,b);
		}

		cout<<v[p-1-s]<<'\n';
	}
}
