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

int l,u,r;

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
	int t=0;
	while(true) {
		++t;
		cin>>l>>u>>r;
		if(!l&&!u&&!r) break;
		vi v;
		int a;
		while(r--) cin>>a,v.pb(a);
		vi result(10000,-1);
		queue<ii> q;
		q.emplace(l,0);
		while(!q.empty()) {
			auto curr = q.front();
			q.pop();
			if(result[curr.fi]==-1) {
				result[curr.fi]=curr.se;
				for(int i: v) {
					int j=(curr.fi+i)%10000;
					if(result[j]==-1) q.emplace(j,curr.se+1);
				}
			}
		}
		cout<<"Case "<<t<<": ";
		if(result[u]==-1) cout<<"Permanently Locked\n";
		else cout<<result[u]<<'\n';
	}
}
