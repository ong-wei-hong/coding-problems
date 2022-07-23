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

int q,n,m,t,s,g,h;

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
	cin>>q;
	while(q--) {
		cin>>n>>m>>t>>s>>g>>h;
		vector<vii> al(n+1);
		while(m--) {
			int a,b,d;
			cin>>a>>b>>d;
			al[a].eb(b,d);
			al[b].eb(a,d);
		}
		vi dest(t);
		forn(i,t) cin>>dest[i];

		vi sssp(n+1,-1);
		vector<bool> valid(n+1,0);
		priority_queue<pair<int,pair<int,bool>>,vector<pair<int,pair<int,bool>>>,greater<pair<int,pair<int,bool>>>> pq;
		pq.push(mp(0,mp(s,false)));

		while(!pq.empty()) {
			auto curr = pq.top();
			pq.pop();
			if((sssp[curr.se.fi]==-1)||(curr.se.se&&curr.fi<=sssp[curr.se.fi])) {
				sssp[curr.se.fi]=curr.fi;
				valid[curr.se.fi]=curr.se.se;
				for(auto& p: al[curr.se.fi]) {
					bool v = curr.se.se||(curr.se.fi==g&&p.fi==h)||(curr.se.fi==h&&p.fi==g);
					int w=p.se+curr.fi;
					if((sssp[p.fi]==-1)||(v&&w<=sssp[p.fi]))
						pq.push(mp(w,mp(p.fi,v)));
				}
			}
		}

		sort(all(dest));
		for(auto i: dest) if(valid[i]) cout<<i<<' ';
		cout<<'\n';
	}
}



