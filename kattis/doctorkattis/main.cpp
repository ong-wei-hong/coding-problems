#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;

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

int N,c,l;
string s;
unordered_map<string,ii> m1;
map<ii,string> m2;


void solve() {
	cin>>c;
	ii p;
	switch(c) {
		case 0:
			cin>>s>>l;
			m1[s]=mp(-l,-N);
			m2[mp(-l,-N)]=s;
			break;
		case 1:
			cin>>s>>l;
			p=m1[s];
			m2.erase(p);
			m1[s]=mp(p.fi-l,p.se);
			m2[mp(p.fi-l,p.se)]=s;
			break;
		case 2:
			cin>>s;
			p=m1[s];
			m1.erase(s);
			m2.erase(p);
			break;
		case 3:
			if(m2.size()) cout<<m2.begin()->se<<'\n';
			else cout<<"The clinic is empty\n";
			break;
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>N;
	while(N--) solve();
}
