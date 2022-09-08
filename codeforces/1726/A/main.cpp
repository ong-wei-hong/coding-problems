#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int, int>>
#define pq priority_queue

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair

int t,n;

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

void cin_ignore() {
	cin.ignore(256,'\n');
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		vector<int> v(n);
		for(auto& i: v) cin>>i;
		int ans=-999;
		for(int i=0;i<n;++i) ans=max(ans,v[(i+n-1)%n]-v[i]);
		for(int i=1;i<n;++i) ans=max(ans,v[i]-v[0]);
		for(int i=0;i<n-1;++i) ans=max(ans,v[n-1]-v[i]);
		cout<<ans<<'\n';
	}
}

