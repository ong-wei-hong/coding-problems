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

int t,n,a,b;

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
		cin>>n>>a;
		vector<int> seen(n+1,n);
		seen[0]=-1;
		seen[a]=-1;
		int ans=0,uniq=1,last_bad=-2;
		forn(i,n-1) {
			cin>>b;
			if(seen[b]<=last_bad) b=0;
			if(b<a) ans=uniq,last_bad=i-1;
			a=b;
			if(seen[b]==n) ++uniq,seen[b]=i;
		}
		cout<<ans<<'\n';
	}
}
