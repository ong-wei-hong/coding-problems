#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()

int t,n,a,b;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		b=0;
		set<int> s;
		forn(i,n) {
			cin>>a;
			b+=(s.find(a)!=s.end());
			s.insert(a);
		}
		b+=(b&1);
		cout<<(n-b)<<'\n';
	}
}
