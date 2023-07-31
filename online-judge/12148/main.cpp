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

int t,d1,m1,yy,c1,d2,m2,y2,c2;

bool leap_year() {
	return yy%400==0||(yy%4==0&&yy%100);
}

bool max_day() {
	if(leap_year()&&m1==2&&d1==30) return true;
	if(!leap_year()&&m1==2&&d1==29) return true;
	if(d1==32&&(m1==1||m1==3||m1==5||m1==7||m1==8||m1==10||m1==12)) return true;
	return d1==31&&(m1==4||m1==6||m1==9||m1==11);
}

void add_one_day() {
	++d1;
	if(max_day()) d1=1,++m1;
	if(m1==13) m1=1,++yy;
}

void solve() {
	int a,b;
	a=b=0;
	cin>>d1>>m1>>yy>>c1;
	while(--t) {
		cin>>d2>>m2>>y2>>c2;
		add_one_day();
		if(d1==d2&&m1==m2&&yy==y2) {
			++a,b+=c2-c1;
		}
		d1=d2,m1=m2,yy=y2,c1=c2;
	}
	cout<<a<<' '<<b<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>t;t;cin>>t) solve();
}
