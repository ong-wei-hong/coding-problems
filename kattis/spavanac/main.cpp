#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)

int h,m;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>h>>m;
	m-=45;
	if(m<0) m+=60,--h;
	if(h<0) h=23;
	cout<<h<<' '<<m<<'\n';
	return 0;
}
