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

int t,n,a;

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(1) {
		cin>>t;
		if(!t) break;
		multiset<int> s;
		long r=0;
		while(t--) {
			cin>>n;
			while(n--) cin>>a,s.insert(a);
			r+=(*s.rbegin()-*s.begin());
			s.erase(s.find(*s.rbegin()));
			s.erase(s.begin());
		
		}
		cout<<r<<'\n';
	}
}
