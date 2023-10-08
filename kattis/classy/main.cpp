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

int t,n;
vector<pair<string,vector<int>>> v;

int h(char c) {
	if(c=='u') return -1;
	if(c=='m') return 0;
	return 1;
}

void help(vector<int>& v, string &s) {
	v.resize(10);
	int i=0;
	for(int j=s.rfind('-');j!=-1;j=s.rfind('-',j-1)) {
		v[i++]=h(s[j+1]);
	}
	v[i++]=h(s[0]);
	for(;i<10;++i) v[i]=0;
}

void solve() {
	cin>>n;
	v.resize(n);
	for(auto& p: v) {
		string s,t;
		cin>>p.fi>>s>>t;
		help(p.se, s);
	}
	sort(all(v),[&](pair<string,vector<int>> &p1, pair<string,vector<int>> &p2) {
		forn(i,10) if(p1.se[i]!=p2.se[i]) return p1.se[i]<p2.se[i];
		return p1.fi<p2.fi;
	});
	for(auto &p: v) cout<<p.fi.substr(0,p.fi.size()-1)<<'\n';
	forn(i,30) cout<<'=';
	cout<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
