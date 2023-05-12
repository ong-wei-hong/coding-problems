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

int t,n,m,x;
vi v;

void solve() {
	cin>>n>>m;
	v.resize(0);
	int l=0,r=0;
	forn(i,n) {
		cin>>x;
		if(x>0) v.pb(x);
		l+=(x==-1);
		r+=(x==-2);
	}
	sort(all(v));
	auto last = unique(all(v));
	v.erase(last,v.end());
	int one=min(m,l+(int)v.size());
	int two=min(m,r+(int)v.size());
	int three=0;
	forn(i,v.size()) {
		int avail_l = v[0]-1+v[i]-v[0]-i;
		int avail_r = m-v.back()+v.back()-v[i]-v.size()+i+1;
		three=max(three,min(avail_l,l)+min(avail_r,r));
	}
	cout<<max(one,max(two,three+(int)v.size()))<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
