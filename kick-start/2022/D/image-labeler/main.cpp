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

int t,n,m,a[10000];

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	cout<<setprecision(10);
	forn(i,t) {
		cin>>n>>m;
		forn(j,n) cin>>a[j];
		sort(a,a+n);
		double b=0;
		forn(j,m-1) b+=a[n-1-j];
		if((n-m)&1) b+=(a[(n-m)>>1]+a[1+((n-m)>>1)])/2.0;
		else b+=a[(n-m)>>1];
		cout<<"Case #"<<i+1<<": "<<b<<'\n';
	}
}
