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

int t,a[3],ms[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};
string s;

void print_date(int y,int m, int d) {
	cout<<y<<'-'<<setfill('0')<<setw(2)<<m<<'-'<<setfill('0')<<setw(2)<<d<<'\n';
}

bool leap(int y) {
	if(y%400==0) return 1;
	if(y%100==0) return 0;
	return y%4==0;
}

bool solve(int yi,int mi,int di) {
	int y=a[yi],m=a[mi],d=a[di];
	if(y<100) y+=2000;
	if(m==0||m>12||d==0||y<2000||y>2999) return false;
	if(leap(y)&&m==2&&d<=29) {
		print_date(y,m,d);
		return true;
	}
	if(!leap(y)&&m==2&&d<=ms[2]) {
		print_date(y,m,d);
		return true;
	}
	if(d<=ms[m]) {
		print_date(y,m,d);
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	int i=s.find('/'),j=s.find('/',i+1);
	a[0]=stoi(s.substr(0,i));
	a[1]=stoi(s.substr(i+1,j-i));
	a[2]=stoi(s.substr(j+1));
	sort(a,a+3);
	if(solve(0,1,2));
	else if(solve(0,2,1));
	else if(solve(1,0,2));
	else if(solve(1,2,0));
	else if(solve(2,0,1));
	else if(solve(2,1,0));
	else cout<<s<<" is illegal\n";
}
