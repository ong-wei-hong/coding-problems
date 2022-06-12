#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)

int x,y;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>x>>y;
	if(x<0&&y<0){ cout<<3<<'\n';return 0;}
	if(x<0){cout<<2<<'\n';return 0;}
	if(y<0){cout<<4<<'\n';return 0;}
	cout<<1<<'\n';
	return 0;
}
