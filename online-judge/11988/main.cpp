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

void solve() {
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    //cin>>t;
    //while(t--) solve();
    while(getline(cin,s)) {
	list<vector<char>> l{};
	l.emplace_front();
	bool back{1};
	for(const auto c: s) 
		switch(c) {
			case '[':
				back=0;
				l.emplace_front();
				break;
			case ']':
				back=1;
				break;
			default:
				if(back) l.back().push_back(c);
				else l.front().push_back(c);
				break;
		}
	for(const auto& v: l) for(const auto c: v) cout<<c;
	cout<<'\n';
    }
}
