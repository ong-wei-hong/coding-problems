#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()

int t,n,m,ak,bk,ck,dk;
ii a,b,c,d;
char ch;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		ak=-1,bk=2001,ck=-1001,dk=1001;
		forn(i,n)
			forn(j,m) {
				cin>>ch;
				if(ch=='B') {
					if(i+j>ak) ak=i+j,a={i,j};
					if(i+j<bk) bk=i+j,b={i,j};
					if(i-j>ck) ck=i-j,c={i,j};
					if(i-j<dk) dk=i-j,d={i,j};
				}
			}
		int mini{2001};
		ii p;
		forn(i,n)
			forn(j,m) {
				int maxi{abs(i-a.first)+abs(j-a.second)};
				maxi=max(maxi,abs(i-b.first)+abs(j-b.second));
				maxi=max(maxi,abs(i-c.first)+abs(j-c.second));
				maxi=max(maxi,abs(i-d.first)+abs(j-d.second));
				if(maxi<mini) mini=maxi,p={i,j};
			}
		cout<<p.first+1<<' '<<p.second+1<<'\n';
	}
	return 0;
}

