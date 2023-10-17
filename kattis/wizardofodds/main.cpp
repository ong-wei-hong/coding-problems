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

string s,t;
vi v1,v2;
bool b=0;

bool minus1() {
	if((v2.size()==1&&v2[0]==0)||v2.size()==0) return false;
	int i=0;
	while(v2[i]==0) v2[i]=9,++i;
	--v2[i];
	if(v2.back()==0) v2.pop_back();
	return true;
}

bool divideby2() {
	if(v1[0]&1) b=1,--v1[0];
	for(int i=v1.size()-1;i>=0;--i) {
		if(v1[i]&1) v1[i-1]+=10;
		v1[i]/=2;
	}
	if(v1.back()==0) v1.pop_back();
	return (v1.size()==1&&v1[0]==1&&!b)||(v1.size()==0);
}

void print() {
	forn(i,v1.size()) cout<<v1[v1.size()-i-1];
	cout<<' ';
	forn(i,v2.size()) cout<<v2[v2.size()-i-1];
	cout<<'\n';
}

void solve() {
	while(minus1()) {
		if(divideby2()) {
			//print();
			cout<<"Your wish is granted!\n";
			return;
		}
		//print();
	}
	//print();
	cout<<"You will become a flying monkey!\n";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s>>t;
	for(auto it=s.rbegin();it!=s.rend();++it) v1.pb((*it)-'0');
	for(auto it=t.rbegin();it!=t.rend();++it) v2.pb((*it)-'0');
	solve();
}
