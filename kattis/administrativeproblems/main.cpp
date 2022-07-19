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

int t,n,m;

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
		cin>>n>>m;
		vector<pair<int,ii>> car_details;
		unordered_map<string,int> cars;
		map<string,pair<int,ll>> agents;
		while(n--) {
			string car;
			int p,q,r;
			cin>>car>>p>>q>>r;
			cars[car]=car_details.size();
			car_details.pb(mp(p,mp(q,r)));
		}
		while(m--) {
			int t,d,s;
			string name,car;
			char c;
			cin>>t>>name>>c;
			auto it=agents.find(name);
			if(it==agents.end()) agents[name]=mp(-1,0),it=agents.find(name);
			auto info=it->se;
			switch(c) {
				case 'p':
					cin>>car;
					if(info.fi!=-1||info.se==-1) {
						info.se=-1;
						break;
					}
					info.fi=cars[car];
					info.se+=car_details[info.fi].se.fi;
					break;
				case 'r':
					cin>>d;
					if(info.fi==-1||info.se==-1) {
						info.se=-1;
						break;
					}
					info.se+=car_details[info.fi].se.se*d;
					info.fi=-1;
					break;
				case 'a':
					cin>>s;
					if(info.fi==-1||info.se==-1) {
						info.se=-1;
						break;
					}
					info.se+=(car_details[info.fi].fi*s+99)/100;
					break;
			}
			agents[name]=info;
		}
		for(auto& it:agents) {
			cout<<it.fi<<' ';
			if(it.se.fi!=-1||it.se.se==-1) cout<<"INCONSISTENT\n";
			else cout<<it.se.se<<'\n';
		}
	}
}
