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
		if(y&1) z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}

ll inv(ll x) {
	return binpow(x, MOD - 2) ;
}

bool prime(ll x) {
	for(ll i=2;i*i<=x;++i)
		if(x%i==0) return false;
	return true;
}

int t,n,a,b;
vector<vi> adj_l;
vi d1,d2,d;

void dfs(int c, int p, int d, vi &v) {
	v[c]=d;
	for(auto i: adj_l[c])
		if(i!=p) dfs(i,c,d+1,v);
}	

void solve() {
	cin>>n;

	adj_l.resize(n);
	forn(i,n-1) {
		cin>>a>>b;
		--a,--b;
		adj_l[a].pb(b);
		adj_l[b].pb(a);
	}

	d1.resize(n);
	d2.resize(n);
	dfs(0,-1,0,d1);
	int a=max_element(all(d1)) - d1.begin();
	dfs(a,-1,0,d1);
	int b=max_element(all(d1)) - d1.begin();
	dfs(b,-1,0,d2);

	d.resize(n);
	forn(i,n) ++d[max(d1[i],d2[i])];
	int ans=0;
	forn(i,n) ans+=d[i], cout<<min(n,ans+1)<<" \n"[i==n-1];
}

int main() {
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//cin>>t;
	//while(t--) solve();
	solve();
}
