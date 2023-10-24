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

int t,a[1000000],b[1000000],A=500000,B=500000,AN=0,BN=0,x;
string s;

void push_back(int *a, int &A, int& an, int val) {
	a[A+an]=val;
	++an;
}

void push_front(int *a, int& A, int& an, int val) {
	--A;
	a[A]=val;
	++an;
}

int pop_front(int *a, int &A, int& an) {
	--an;
	return a[A++];
}

int pop_back(int *a, int &A, int &an) {
	return a[A+(--an)];
}

void balance() {
	if(AN>BN+1) push_front(b,B,BN,pop_back(a,A,AN));
	else if(BN>AN) push_back(a,A,AN,pop_front(b,B,BN));
}

void check() {
	cout<<"CHECK\n";
	cout<<s<<' '<<x<<'\n';
	forn(i,AN) cout<<a[A+i]<<' ';
	cout<<'\n';
	forn(i,BN) cout<<b[B+i]<<' ';
	cout<<'\n';
	cout<<"CHECK\n";
}

void solve() {
	cin>>s>>x;
	if(s=="push_back") {
		push_back(b,B,BN,x);
		balance();
	} else if(s=="push_front") {
		push_front(a,A,AN,x);
		balance();
	} else if(s=="push_middle") {
		push_back(a,A,AN,x);
		balance();
	} else if(s=="get") {
		if(x>=AN) cout<<b[B+x-AN]<<'\n';
		else cout<<a[A+x]<<'\n';
	}
	//check();
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
