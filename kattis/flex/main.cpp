#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()

int w,p,l[101];
set<int> s;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>w>>p;
	forn(i,p)cin>>l[i],s.insert(l[i]),s.insert(w-l[i]);
	forn(i,p)
		for(int j=i+1;j<p;++j)
			s.insert(l[j]-l[i]);
	for(auto it{s.begin()};it!=s.end();++it)
		cout<<(*it)<<' ';
	cout<<w<<'\n';
	return 0;
}
