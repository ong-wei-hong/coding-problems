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

ll n,m,i,x,ans;

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
	cin>>n>>m;
	vll v(n,0);
	for(auto& i: v) cin>>i;
	forn(i,n-1) ans+=(v[i]!=v[i+1])*(i+1)*(n-i-1);
	ans+=n*(n+1)/2;
	while(m--) {
		cin>>i>>x;
		--i;
		if(i) ans-=(v[i]!=v[i-1])*i*(n-i),ans+=(x!=v[i-1])*i*(n-i);
		if(i<n-1) ans-=(v[i]!=v[i+1])*(i+1)*(n-1-i),ans+=(x!=v[i+1])*(i+1)*(n-1-i);
		v[i]=x;
		cout<<ans<<'\n';
	}
}
