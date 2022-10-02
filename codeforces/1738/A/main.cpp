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

void cin_ignore() {
	cin.ignore(256,'\n');
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		vi v(n);
		for(auto& i: v) cin>>i;
		vll v1,v2;
		forn(i,n){
			if(v[i]) cin>>a,v1.pb(a);
			else cin>>a,v2.pb(a);
		}
		if(v1.empty()||v2.empty()) {
			ll ans=0;
			for(auto i: v1) ans+=i;
			for(auto i: v2) ans+=i;
			cout<<ans<<'\n';
			continue;
		}
		sort(all(v1));
		sort(all(v2));
		ll ans1=0,ans2=0;
		int p1=v1.size()-1,p2=v2.size()-1;
		ans1+=v1[0];
		while(1){
			if(p2<0) break;
			ans1+=2*v2[p2--];
			if(p1<=0) break;
			ans1+=2*v1[p1--];
		}
		while(p1>0) ans1+=v1[p1--];
		while(p2>=0) ans1+=v2[p2--];
		p1=v1.size()-1;
		p2=v2.size()-1;
		ans2+=v2[0];
		while(1){
			if(p1<0) break;
			ans2+=2*v1[p1--];
			if(p2<=0) break;
			ans2+=2*v2[p2--];
		}
		while(p2>0) ans2+=v2[p2--];
		while(p1>=0) ans2+=v1[p1--];
		cout<<max(ans1,ans2)<<'\n';
	}
}
		
