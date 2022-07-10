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

int n,a;

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>n;
	vi v(n);
	forn(i,n) cin>>v[i];
	sort(all(v));
	forn(i,(n/2)+1) a+=v[i]/2;
	forn(i,n/2) a+=v[i+(n/2)+1];
	cout<<a<<'\n';
}
