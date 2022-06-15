#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()

int t;
const ii pairs[4] {{-1,-1},{-1,1},{1,1},{1,-1}};
string b[8];
bool c[4];

void solve() {
	forn(i,8) cin>>b[i];
	forn(i,8)
		forn(j,8)
			if(b[i][j]=='#') {
				forn(k,4) {
					int x=i+pairs[k].first,y=j+pairs[k].second;
					c[k]=((x>=0)&&(x<8)&&(y>=0)&&(y<8)&&b[x][y]=='#');
				}
				if((c[0]&&c[1])||(c[1]&&c[2])||(c[2]&&c[3])||(c[3]&&c[0])) {
					cout<<i+1<<' '<<j+1<<'\n';
					return;
				}
			}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--) solve();
}
