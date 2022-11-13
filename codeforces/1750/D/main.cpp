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

int ufds_find_set(vi& ufds, int i){
	if(ufds[i]==i) return i;
	return ufds[i]=ufds_find_set(ufds,ufds[i]);
}

void ufds_union_set(vi& ufds, vi& rank, int i, int j){
	i = ufds_find_set(ufds,i);
	j = ufds_find_set(ufds,j);
	if(i==j) return;
	if(rank[i]>rank[j]) ufds[j]=i;
	else ufds[i]=j,++rank[j];
}

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

vi get_primes(int n) {
	int d=2;
	vi ans;
	while(d*d<=n){
		bool added=0;
		while(n%d==0){
			n/=d;
			added=1;
		}
		if(added){
			ans.pb(d);
		}
		++d;
	}
	if(n!=1) ans.pb(n);
	return ans;
}

int t,n,m;
vi a;

void solve(){
	forn(i,n-1)
		if(a[i]%a[i+1]!=0){
			cout<<"0\n";
			return;
		}

	vi primes = get_primes(a[0]);
	ll ans=1;
	forn(i,n-1){
		int l=a[i]/a[i+1],limit=m/a[i+1],r=0;
		vi l_primes;
		for(auto i: primes) if(l%i==0) l_primes.pb(i);
		for(int mask=0;mask<(1<<l_primes.size());++mask){
			int prod=1,cnt=0;
			for(int j=0;j<l_primes.size();++j) if(mask&(1<<j)) prod*=l_primes[j],++cnt;
			if(cnt&1) r-=limit/prod;
			else r+=limit/prod;
		}
		ans=mul(ans,r);
	}
	cout<<ans<<'\n';
}


int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		a.resize(n);
		for(auto& i: a) cin>>i;
		solve();
	}
}
