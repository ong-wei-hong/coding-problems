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

int p,a,b,c,d,n;

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

void cin_ignore() {
	cin.ignore(256,'\n');
}

double price(int k) {
	return p * (sin(a*k+b)+cos(c*k+d)+2);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>p>>a>>b>>c>>d>>n;
	double ma=price(1),curr,ans=0;
	for(int i=2;i<=n;++i) curr=price(i),ans=max(ans,ma-curr),ma=max(ma,curr);
	cout<<fixed<<setprecision(10)<<ans<<'\n';
}
