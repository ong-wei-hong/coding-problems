#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
int t,n,m,k;
string a,b;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n>>m>>k>>a>>b;
		sort(all(a));
		sort(all(b));
		auto i{a.begin()};
		auto j{b.begin()};
		int c{0},d{0};
		while(i!=a.end()&&j!=b.end()) {
			bool e{(*i)<(*j)};
			if(e&&c==k) e=0;
			if(!e&&d==k) e=1;
			if(e) cout<<(*i),++i,++c,d=0;
			else cout<<(*j),++j,++d,c=0;
		}
		cout<<'\n';
	}
	return 0;
}


