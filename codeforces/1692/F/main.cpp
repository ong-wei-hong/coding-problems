#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int t,n;

void solve() {
	cin>>n;
	vi a(10);
	int x;
	forn(i,n) cin>>x,++a[x%10];
	vi v;
	forn(i,10) forn(j,min(a[i],3)) v.push_back(i);
	forn(i,v.size()) for(int j=i+1;j<v.size();++j) for(int k=j+1;k<v.size();++k)
		if((v[i]+v[j]+v[k])%10==3) {
			cout<<"YES\n";
			return;
		}
	cout<<"NO\n";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--) solve();
}
