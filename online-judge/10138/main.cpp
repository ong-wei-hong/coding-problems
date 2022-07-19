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

int t;

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
	cout<<fixed<<setprecision(2);
	while(t--) {
		vi fares(24);
		forn(i,24) cin>>fares[i];
		cin_ignore();
		string line;
		map<string,vector<pair<string,pair<bool,int>>>> cars;
		while(1) {
			getline(cin,line);
			if(line=="") break;
			int a=line.find(' '),b=line.find(' ',a+1),c=line.find(' ',b+1);
			string plate=line.substr(0,a),time=line.substr(a+1,b-a-1);
			bool enter=line[b+2]=='n';
			int d=stoi(line.substr(c+1));

			pair<string,pair<bool,int>> info=mp(time,mp(enter,d));
			auto it = cars.find(plate);
			if(it==cars.end()) {
				vector<pair<string,pair<bool,int>>> v;
				v.pb(info);
				cars[plate]=v;
			} else it->se.pb(info);
		}
		for(auto& it: cars) {
			auto v = it.se;
			ll price=200;
			sort(all(v));
			for(int i=0;i<v.size()-1;++i) if(v[i].se.fi&&!v[i+1].se.fi)
				price+=100+abs(v[i+1].se.se-v[i].se.se)*fares[stoi(v[i].fi.substr(6,2))];
			if(price!=200) cout<<it.fi<<" $"<<setprecision(2)<<price/100.0<<'\n';
		}
		if(t) cout<<'\n';
	}
}




