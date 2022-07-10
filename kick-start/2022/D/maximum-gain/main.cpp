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

int t,n,m,k;

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	forn(i,t) {
		cin>>n;
		vi a(n);
		forn(j,n) cin>>a[j];

		cin>>m;
		vi b(m);
		forn(j,m) cin>>b[j];

		cin>>k;

		vll aa(n+1);
		forn(j,n) aa[j+1]+=aa[j]+a[j];
		int nn=min(n,k);
		vll aaa(nn+1);
		forn(j,nn+1) {
			ll ma=0;
			forn(x,j+1) ma=max(ma,aa[x]+aa[n]-aa[n+x-j]);
			aaa[j]=ma;
		}
		
		vll bb(m+1);
		forn(j,m) bb[j+1]+=bb[j]+b[j];
		int mm=min(m,k);
		vll bbb(mm+1);
		forn(j,mm+1) {
			ll ma=0;
			forn(x,j+1) ma=max(ma,bb[x]+bb[m]-bb[m+x-j]);
			bbb[j]=ma;
		}

		ll ans=0;
		forn(j,nn+1) ans=max(ans,aaa[j]+bbb[min(k-j,mm)]);
		cout<<"Case #"<<i+1<<": "<<ans<<'\n';
	}
}
		
		
