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
string s,t,a,b,c;
unordered_map<string,string> domain;
unordered_set<string> codomain;

void solve() {
	domain = unordered_map<string,string>();
	codomain = unordered_set<string>();

	getline(cin,t);
	int j=0;
	for(int i=t.find(" ");i!=-1;i=t.find(" ",i+1)) ++j;
	cin>>n;
	bool v=1,inj=1;
	forn(i,n) {
		cin>>a>>b>>c;
		auto it=domain.find(a);
		if(it!=domain.end()&&it->se==c) continue;

		if(it!=domain.end()&&it->se!=c) v=0;
		auto it2=codomain.find(c);
		if(it2!=codomain.end()) inj=0;

		domain[a]=c;
		codomain.insert(c);
	}

	if(!v) cout<<"not a function\n";
	else if(inj&&codomain.size()==j) cout<<"bijective\n";
	else if(inj) cout<<"injective\n";
	else if(codomain.size()==j) cout<<"surjective\n";
	else cout<<"neither injective nor surjective\n";

	cin.ignore(255,'\n');
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(getline(cin,s)) {
		if(s=="") break;
		solve();
	}
}
