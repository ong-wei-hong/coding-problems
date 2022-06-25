#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int t;
string s,u;

void solve() {
	getline(cin,s);
	unordered_set<string> se;
	while(true) {
		getline(cin,u);
		if(!u.compare("what does the fox say?")) break;
		string v=u.substr(u.rfind(" ")+1);
		se.insert(v);
	}
	int i=0,j=-1;
	while(true) {
		j=s.find(" ",j+1);
		if(j==string::npos) break;
		string v=s.substr(i,j-i);
		if(se.find(v)==se.end()) cout<<v<<' ';
		i=j+1;
	}
	string v=s.substr(i);
	if(se.find(v)==se.end()) cout<<v;
	cout<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	cin.ignore(256,'\n');
	while(t--) solve();
}
