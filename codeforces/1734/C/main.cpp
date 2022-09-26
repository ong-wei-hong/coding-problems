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
	while(t--){
		cin>>n;
		vector<bool> v(n);
		vector<bool> d(n);
		char c;
		forn(i,n) cin>>c,v[i]=c=='1';
		ll ans=0;
		forn(i,n) if(!v[i]){
			int j=i;
			while(j<n&&!v[j]) {
				if(!d[j]) ans+=i+1,d[j]=1;
				j+=i+1;
			}
		}
		cout<<ans<<'\n';
	}
}
