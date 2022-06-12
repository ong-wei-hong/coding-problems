#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()

int a[1000],b[1000],t,n;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		forn(i,n) cin>>a[i],b[i]=i+1;
		if(n==1) {
			cout<<-1<<'\n';
			continue;
		}
		forn(i,n-1)
			if(a[i]==b[i])
				swap(b[i],b[i+1]);
		if(b[n-1]==a[n-1]) swap(b[n-1],b[n-2]);
		forn(i,n) cout<<b[i]<<' ';
		cout<<'\n';
	}
	return 0;
}
