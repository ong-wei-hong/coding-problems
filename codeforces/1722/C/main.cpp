#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int, int>>
#define pq priority_queue

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair

int t,n;
string s;

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

void cin_ignore() {
	cin.ignore(256,'\n');
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		unordered_map<string,int> m;
		cin>>n;
		vector<vector<string>> v(3);
		forn(i,3) 
			forn(j,n) {
				cin>>s;
				if(m.find(s)==m.end()) m[s]=0;
				++m[s];
				v[i].pb(s);
			}
		forn(i,3) {
			int p=0;
			for(auto& s: v[i]) {
				int q=m[s];
				if(q==1) p+=3;
				else if(q==2) ++p;
			}
			cout<<p<<' ';
		}
		cout<<'\n';
	}
}
