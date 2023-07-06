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

int t,i;
string s;
vi v;

bool input() {
	v.clear();
	int a,b,c;
	cin>>a>>b>>c;
	if(!a&&!b&&!c) return false;
	v.pb(a);
	v.pb(b);
	for(i=c;i!=0;cin>>i) v.pb(i);
	return true;
}

void solve() {
	for(int i=*min_element(all(v));i<=5*3600;++i) {
		bool solved=true;
		for(auto j: v) {
			if((i/j)&1) {
				solved=false;
				break;
			}
			if(j-(i%j)<=5) {
				solved=false;
				break;
			}
		}
		if(solved) {
			cout<<setfill('0')<<setw(2)<<i/3600<<':';
			cout<<setfill('0')<<setw(2)<<(i/60)%60<<':';
			cout<<setfill('0')<<setw(2)<<i%60<<'\n';
			return;
		}
	}
	cout<<"Signals fail to synchronise in 5 hours\n";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(input()) solve();
}
