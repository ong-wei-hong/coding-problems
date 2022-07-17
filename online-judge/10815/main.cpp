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

string s;
set<string> se;
const string a{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(getline(cin,s)) {
		int start=s.find_first_of(a);
		int end;
		while(start!=string::npos) {
			end=s.find_first_not_of(a,start);
			if(end==string::npos) {
				string t = s.substr(start);
				for(auto& c: t) c=tolower(c);
				se.insert(t);
				break;
			}
			string t = s.substr(start,end-start);
			for(auto& c: t) c=tolower(c);
			se.insert(t);
			start=s.find_first_of(a,end);
		}
	}
	for(auto& t: se) cout<<t<<'\n';
}



