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

int t,c,d[3];

bool leap(ll y) {
	if(y%400==0) return 1;
	else if(y%100==0) return 0;
	else if(y%4==0) return 1;
	return 0;
}

bool valid(int y, int m, int d) {
	if(leap(y+100LL*c)&&m==2) return d>=1&&d<=29;
	else if(m==2) return d>=1&&d<=28;
	else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) return d>=1&&d<=31;
	else if(m==4||m==6||m==9||m==11) return d>=1&&d<=30;
	return false;
}

void print(int a) {
	if(a<10) cout<<'0'<<a;
	else cout<<a;
}

void print_date(int y, int m,int d) {
	print(y);
	cout<<' ';
	print(m);
	cout<<' ';
	print(d);
	cout<<'\n';
}

void solve() {
	cin>>c>>d[0]>>d[1]>>d[2];
	sort(d,d+3);
	if(valid(d[0],d[1],d[2])) {
		print_date(d[0],d[1],d[2]);
		return;
	}
	if(valid(d[0],d[2],d[1])) {
		print_date(d[0],d[2],d[1]);
		return;
	}
	if(valid(d[1],d[0],d[2])) {
		print_date(d[1],d[0],d[2]);
		return;
	}
	if(valid(d[1],d[2],d[0])) {
		print_date(d[1],d[2],d[0]);
		return;
	}
	if(valid(d[2],d[0],d[1])) {
		print_date(d[2],d[0],d[1]);
		return;
	}
	if(valid(d[2],d[1],d[0])) {
		print_date(d[2],d[1],d[0]);
		return;
	}
	cout<<"-1\n";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
