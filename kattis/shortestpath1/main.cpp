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

int n,m,q,s;

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(1) {
		cin>>n>>m>>q>>s;
		if(!n&&!m&&!q&&!s) break;
		vector<vii> al(n);
		while(m--) {
			int a,b,c;
			cin>>a>>b>>c;
			al[a].eb(b,c);
		}
		vi w(n,-1);
		pq<ii,vii,greater<ii>> prq;
		prq.emplace(0,s);
		while(!prq.empty()) {
			ii c=prq.top();
			prq.pop();
			if(w[c.se]==-1) {
				w[c.se]=c.fi;
				for(auto& i: al[c.se]) if(w[i.fi]==-1) prq.emplace(c.fi+i.se,i.fi);
			}
		}
		while(q--) {
			int e;
			cin>>e;
			if(w[e]==-1) cout<<"Impossible\n";
			else cout<<w[e]<<'\n';
		}
	}
}
