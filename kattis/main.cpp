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

int n,m,f,s,t;

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
	cin>>n>>m>>f>>s>>t;

	vector<vii> al(n);
	while(m--) {
		int i,j,c;
		cin>>i>>j>>c;
		al[i].eb(j,c);
		al[j].eb(i,c);
	}
	
	vector<vi> flights(n);
	while(f--) {
		int u,v;
		cin>>u>>v;
		flights[u].pb(v);
	}

	vector<pair<ll,ll>> sssp(n,mp(-1,-1));
	priority_queue<pair<ll,pair<int,bool>>,vector<pair<ll,pair<int,bool>>>,greater<pair<ll,pair<int,bool>>>> pq;
	pq.push(mp(0,mp(s,false)));
	while(!pq.empty()) {
		auto curr=pq.top();
		pq.pop();
		int curr_v=curr.se.fi;
		if(curr.se.se&&(sssp[curr_v].se==-1||sssp[curr_v].se>curr.fi)) {
			sssp[curr_v].se=curr.fi;
			for(auto& p: al[curr_v]) {
				ll new_w=curr.fi+p.se;
				if(sssp[p.fi].se==-1||sssp[p.fi].se>new_w) pq.push(mp(new_w,mp(p.fi,true)));
			}
		} else if(!curr.se.se&&(sssp[curr_v].fi==-1||sssp[curr_v].fi>curr.fi)) {
			sssp[curr_v].fi=curr.fi;
			if(sssp[curr_v].se==-1||sssp[curr_v].se>curr.fi) sssp[curr_v].se=curr.fi;
			for(auto& p: al[curr_v]) {
				ll new_w=curr.fi+p.se;
				if(sssp[p.fi].fi==-1||sssp[p.fi].se>new_w) pq.push(mp(new_w,mp(p.fi,false)));
			}
			for(auto i: flights[curr_v]) if(sssp[i].se==-1||sssp[i].se>curr.fi) pq.push(mp(curr.fi,mp(i,true)));
		}
	}
	cout<<sssp[t].se<<'\n';
}
