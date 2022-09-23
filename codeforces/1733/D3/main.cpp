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

int t,n;
ll x,y;
string a,b;

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
		cin>>n>>x>>y>>a>>b;
		vi v;
		forn(i,n) if(a[i]!=b[i]) v.pb(i);
		if(v.size()&1) cout<<"-1\n";
		else if(v.size()==0) cout<<"0\n";
		else if(x>=y)
			if(v.size()==2&&v[0]+1==v[1])cout<<min(2*y,x)<<'\n';
			else cout<<y*v.size()/2<<'\n';
		else{
			vll dp(v.size());
			dp[0]=0;
			dp[1]=min((v[1]-v[0])*x,y);
			for(int i=2;i<v.size();++i)
				if(i&1) dp[i]=min(dp[i-2]+(v[i]-v[i-1])*x,dp[i-1]+y);
				else dp[i]=min(dp[i-2]+(v[i]-v[i-1])*x,dp[i-1]);
			cout<<dp[v.size()-1]<<'\n';
		}
	}
}

