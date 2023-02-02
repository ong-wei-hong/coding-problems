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

const ll MOD = 998244353;

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

void cin_ignore() {
	cin.ignore(256,'\n');
}

struct ufds {
	vi v,rank;
	void init(int n) {
		v.resize(n);
		forn(i,n) v[i]=i;
		rank.resize(n);
		forn(i,n) rank[i]=1;
	}
	int find(int i) {
		if(v[i]==i) return i;
		return v[i]=this->find(v[i]);
	}
	void union_set(int i, int j){
		i=this->find(i);
		j=this->find(j);
		if(i==j) return;
		if(rank[i]>rank[j]) v[j]=i;
		else v[i]=j,++rank[j];
	}
};

ll add(ll x, ll y) {
	x+=y;
	while(x>=MOD) x-=MOD;
	while(x<0) x+=MOD;
	return x;
}

ll sub(ll x, ll y) {
	return add(x, -y);
}

ll mul(ll x, ll y) {
	return (x*y)%MOD;
}

ll binpow(ll x, ll y) {
	ll z=1;
	while(y){
		if(y&1) z*=x;
		x=mul(x,x);
		y>>=1;
	}
	return z;
}

bool prime(ll x) {
	for(ll i=2;i*i<=x;++i)
		if(x%i==0) return false;
	return true;
}

constexpr int N=200001;
int t,n,s;
ll x[N],y[N], dp[N][2];

void solve() {
	cin>>n>>s;
	for(int i=1;i<=n;++i) {
		int a;
		cin>>a;
		if(i==1||i==n) x[i]=y[i]=a;
		else if(a<=s) x[i]=0,y[i]=a;
		else x[i]=s,y[i]=a-s;
	}
	dp[1][0]=dp[1][1]=0;
	for(int i=2;i<=n;++i) {
		dp[i][0] = min(dp[i-1][0]+y[i-1]*x[i],dp[i-1][1]+x[i-1]*x[i]);
		dp[i][1] = min(dp[i-1][0]+y[i-1]*y[i],dp[i-1][1]+x[i-1]*y[i]);
	}
	cout<<dp[n][0]<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
