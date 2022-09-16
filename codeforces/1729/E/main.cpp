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
	for(int i=2;i<=25;++i) {
		cout<<"? 1 "<<i<<endl;
		ll x,y;
		cin>>x;;
		if(x==-1) {
			cout<<"! "<<i-1<<'\n';
			return 0;
		}
		cout<<"? "<<i<<" 1"<<endl;
		cin>>y;
		if(x!=y) {
			cout<<"! "<<x+y<<'\n';
			return 0;
		}
	}
}
