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
string s;

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
		cin>>n>>s;
		ll ans=0;
		forn(i,n)
			if(s[i]=='L') ans+=i;
			else ans+=(n-i-1);
		int p=0;
		forn(i,n/2) {
			if(s[i]=='L') ans+=(n-1-2*i),cout<<ans<<' ',++p;
			if(s[n-i-1]=='R') ans+=(n-1-2*i),cout<<ans<<' ',++p;
		}
		while(p<n) cout<<ans<<' ',++p;
		cout<<'\n';
	}
}
