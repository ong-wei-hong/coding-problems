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

int t,n,x,tt;

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
	while(t--){
		cin>>n;
		vii v(n);
		for(auto& p: v) cin>>p.fi;
		for(auto& p: v) cin>>p.se;
		int lb=v[0].fi,rb=v[0].fi,ltt=v[0].se,rtt=v[0].se;
		double ans=lb,cost=ltt;
		for(auto& p: v) {
			x=p.fi,tt=p.se;
			double curr_cost=tt+abs(x-ans);
			if(curr_cost>=cost){
				if(x>ans) ans=min((double)x,ans+(curr_cost-cost)/2);
				else ans=max((double)x,ans-(curr_cost-cost)/2);
				if((ans-lb+ltt<curr_cost)||x<lb) lb=x,ltt=tt;
				if((rb-ans+rtt<curr_cost)||x>rb) rb=x,rtt=tt;
				cost=tt+abs(ans-x);
			}
		}
		cout<<fixed<<setprecision(10)<<ans<<'\n';
	}
}
