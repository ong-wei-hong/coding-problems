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

int t;
string s;
vector<string> m;
ii a[10],b[26],c[26];

void connect(ii a, ii b) {
	if(a.fi==b.fi) for(int i=min(a.se,b.se);i<=max(a.se,b.se);++i) {
		if(m[a.fi][i]=='.') m[a.fi][i]='-';
		else if(m[a.fi][i]=='|') m[a.fi][i]='+';
	}
	else if(a.se==b.se) for(int i=min(a.fi,b.fi);i<=max(a.fi,b.fi);++i) {
		if(m[i][a.se]=='.') m[i][a.se]='|';
		else if(m[i][a.se]=='-') m[i][a.se]='+';
	}
}

void solve() {
	int al=-1,bl=-1,cl=-1;

	forn(i,m.size()) forn(j,m[i].size()) {
		char ch=m[i][j];
		if('0'<=ch&&ch<='9') a[ch-'0']=mp(i,j),al=max(al,ch-'0');
		else if('a'<=ch&&ch<='z') b[ch-'a']=mp(i,j),bl=max(bl,ch-'a');
		else if('A'<=ch&&ch<='Z') c[ch-'A']=mp(i,j),cl=max(cl,ch-'A');
	}

	for(int i=0;i<al;++i) connect(a[i],a[i+1]);
	for(int i=0;i<bl;++i) connect(b[i],b[i+1]);
	for(int i=0;i<cl;++i) connect(c[i],c[i+1]);
	if(bl>=0) connect(a[9],b[0]);
	if(cl>=0) connect(b[25],c[0]);

	for(auto &s: m) cout<<s<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	bool f=1;
	while(getline(cin,s)) {
		if(s=="") {
			if(f) f=0;
			else cout<<'\n';
			solve();
			m.clear();
		} else m.pb(s);
	}
	if(f) f=0;
	else cout<<'\n';
	solve();
}
