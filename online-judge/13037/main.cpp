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

int t,a,b,c,n;

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	forn(i,t) {
		cin>>a>>b>>c;
		set<int> sa,sb,sc;
		while(a--) cin>>n,sa.insert(n);
		while(b--) cin>>n,sb.insert(n);
		while(c--) cin>>n,sc.insert(n);
		int al=0,ar=0,bl=0,br=0,cl=0,cr=0;
		for(auto i: sa) {
			auto itb=sb.find(i),itc=sc.find(i);
			if(itb==sb.end()&&itc==sc.end()) ++al;
			else if(itb==sb.end()) br+=itb==sb.end();
		}
		for(auto i: sb) {
			auto ita=sa.find(i),itc=sc.find(i);
			if(ita==sa.end()&&itc==sc.end()) ++bl;
			else if(itc==sc.end()) cr+=itc==sc.end();
		}
		for(auto i: sc) {
			auto ita=sa.find(i),itb=sb.find(i);
			if(ita==sa.end()&&itb==sb.end()) ++cl;
			else if(ita==sa.end()) ar+=ita==sa.end();
		}
		cout<<"Case #"<<i+1<<":\n"<<al<<' '<<ar<<'\n'<<bl<<' '<<br<<'\n'<<cl<<' '<<cr<<'\n';
	}
}
