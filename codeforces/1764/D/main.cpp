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

void solve();

ll n,p,C[5001][5001],fac[5001];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>p;
	forn(i,n+1) C[i][0]=1;
	for(int i=1;i<=n;++i) for(int j=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	fac[0]=fac[1]=1;
	for(int i=2;i<=n;++i) fac[i]=(fac[i-1]*i)%p;

	int t=n/2;
	ll ans=0;
	for(int i=t;i<=n-2;++i)
		for(int j=0;j<=n-i-2;++j)
			ans=(ans+n*(2*t-i)*C[n-i-2][j]%p*fac[i+j-1])%p;
	if(n%2==0) ans=(ans+n*fac[n-2]%p)%p;
	cout<<ans<<'\n';
}
