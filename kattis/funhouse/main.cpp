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

int w,l,x,y,d;
vector<string> v;

void find_start() {
	forn(i,w) if(v[0][i]=='*') {
		x=i,y=0;
		d=1;
	} else if(v.back()[i]=='*') {
		x=i,y=l-1;
		d=3;
	}

	forn(i,l) if(v[i][0]=='*') {
		x=0,y=i;
		d=0;
	} else if(v[i][w-1]=='*') {
		x=w-1,y=i;
		d=2;
	}
}

void solve() {
	v.resize(l);
	for(auto &s: v) cin>>s;

	int dx[4]{1,0,-1,0},dy[4]{0,1,0,-1};
	find_start();
	
	while(v[y][x]!='x') {
		y+=dy[d];
		x+=dx[d];

		if(v[y][x]=='\\') d^=1;
		else if(v[y][x]=='/') d^=3;
	}

	v[y][x]='&';
	for(auto &s: v) cout<<s<<'\n';
	
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int t=1;1;++t) {
		cin>>w>>l;
		if(!w&&!l) break;
		cout<<"HOUSE "<<t<<'\n';
		solve();
	}
}
