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

bool leap(int y) {
	if(y%400==0) return 1;
	if(y%100==0) return 0;
	return y%4==0;
}

int get_days(int m, int y) {
	int ms[13] {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(leap(y)&&m==2) return 29;
	return ms[m];
}


void calculate(int &m, int &d,int &y) {
	for(int days=get_days(m,y);d>days;days=get_days(m,y)) {
		d-=days;
		++m;
		if(m==13) m=1,++y;
	}
}

string signs[13] {"","aquarius","pisces","aries","taurus","gemini","cancer","leo","virgo","libra","scorpio","sagittarius","capricorn"};
int offset[13] {0,20,19,20,20,21,21,22,21,23,23,22,22};
void solve() {
	cin>>s;
	int m=stoi(s.substr(0,2)),d=stoi(s.substr(2,2)),y=stoi(s.substr(4,4));
	d+=40*7;
	calculate(m,d,y);
	cout<<setfill('0')<<setw(2)<<m<<'/'<<setfill('0')<<setw(2)<<d<<'/'<<setfill('0')<<setw(4)<<y<<' ';
	int i=m;
	if(d<=offset[i]) {
		--i;
		if(i==0) i=12;
	}
	cout<<signs[i]<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	forn(i,t) cout<<(i+1)<<' ',solve();
}
