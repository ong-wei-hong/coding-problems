#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

string s;
deque<char> q;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	//cin>>t;
	//while(t--) solve();
	cin>>s;
	for(const auto& c: s)
		if(c=='<') q.pop_back();
		else q.push_back(c);
	for(auto it=q.begin();it!=q.end();++it) cout<<*it;
	cout<<'\n';
}
