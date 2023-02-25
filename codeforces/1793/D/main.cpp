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

int n; 

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	vll pos_a(n+1), pos_b(n+1);
	
	int a;
	forn(i,n) cin>>a,pos_a[a]=i+1;
	forn(i,n) cin>>a,pos_b[a]=i+1;

	ll max_la=n,min_ra=1,max_lb=n,min_rb=1,ans=0;
	for(int i=1;i+1<=n;++i) {
		max_la=min(max_la, pos_a[i]);
		min_ra=max(min_ra, pos_a[i]);
		max_lb=min(max_lb, pos_b[i]);
		min_rb=max(min_rb, pos_b[i]);

		int min_la,max_ra,min_lb,max_rb;
		if(pos_a[i+1]<max_la) {
			min_la=pos_a[i+1]+1;
			max_ra=n;
		} else {
			min_la=1;
			max_ra=pos_a[i+1]-1;
		}
		if(pos_b[i+1]<max_lb) {
			min_lb=pos_b[i+1]+1;
			max_rb=n;
		} else {
			min_lb=1;
			max_rb=pos_b[i+1]-1;
		}
		ans += max(min(max_la,max_lb) - max(min_la, min_lb) + 1, 0ll) * max(min(max_ra, max_rb) - max(min_ra, min_rb) + 1, 0ll);
	}

	ans += min(pos_a[1], pos_b[1]) * (min(pos_a[1], pos_b[1])-1) / 2;
	ans += (n - max(pos_a[1], pos_b[1])) * (n - max(pos_a[1], pos_b[1]) + 1) / 2;
	ans += abs(pos_a[1] - pos_b[1]) * (abs(pos_a[1] - pos_b[1]) - 1) / 2;
	++ans;
	cout<<ans<<'\n';
}
