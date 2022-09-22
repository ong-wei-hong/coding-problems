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
ll x,y;
string a,b;

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
	while(t--){
		cin>>n>>x>>y>>a>>b;
		vector<bool> c(n);
		ll d=0;
		forn(i,n) c[i]=(a[i]!=b[i]),d+=c[i];
		if(d&1) {
			cout<<"-1\n";
			continue;
		}
		if(d==2){
			forn(i,n) if(c[i]) {
				if(c[i+1]) cout<<min(x,2*y)<<'\n';
				else cout<<y<<'\n';
				break;
			}
			continue;
		}
		cout<<d/2*y<<'\n';
	}
}
			

