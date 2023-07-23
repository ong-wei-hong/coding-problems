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
string p1,p2,c;
string abomap[4]{"A","B","O","AB"},rhmap[2]{"-","+"};

ii convert(string b) {
	int abo;
	switch(b[0]) {
		case 'A': abo=0; break;
		case 'B': abo=1; break;
		case 'O': abo=2; break;
	}
	if(b[1]=='B') abo=3;

	return mp(abo,b.back()=='+');
}

bool check_ab(int a, int b) {
	if(a>b) swap(a,b);
	if(b==3) return a!=2;
	return a==0&&b==1;
}

void print_set(bool *abo, bool *rh) {
	if(abo[0]+abo[1]+abo[2]+abo[3]==1&&rh[0]+rh[1]==1) {
		forn(i,4) forn(j,2) if(abo[i]&&rh[j]) {
			cout<<abomap[i]<<rhmap[j];
			return;
		}
	}

	cout<<"{";
	bool f=1;
	forn(i,4) forn(j,2) if(abo[i]&&rh[j]) {
		if(f) f=0;
		else cout<<", ";

		cout<<abomap[i]<<rhmap[j];
	}
	cout<<"}";
}

void find_child(string p1, string p2) {
	bool abo[4]{0,0,0,0},rh[2]{1,0};

	ii p1ii=convert(p1),p2ii=convert(p2);
	abo[0]=p1ii.fi==0||p1ii.fi==3||p2ii.fi==0||p2ii.fi==3;
	abo[1]=p1ii.fi==1||p1ii.fi==3||p2ii.fi==1||p2ii.fi==3;
	abo[2]=p1ii.fi!=3&&p2ii.fi!=3;
	abo[3]=check_ab(p1ii.fi,p2ii.fi);

	rh[1]=p1ii.se==1||p2ii.se==1;
	
	print_set(abo,rh);
}

void find_parent(string p, string c) {
	bool abo[4]{0,0,0,0},rh[2]{0,1};
	ii pii=convert(p),cii=convert(c);

	abo[0]=(pii.fi==1)||(cii.fi==0)||(pii.fi==cii.fi)||(pii.fi==0&&cii.fi==2)||(pii.fi==3&&cii.fi!=2);
	abo[1]=(pii.fi==0)||(cii.fi==1)||(pii.fi==cii.fi)||(pii.fi==1&&cii.fi==2)||(pii.fi==3&&cii.fi==0);
	abo[2]=(pii.fi<3&&(cii.fi==pii.fi||cii.fi==2))||(pii.fi==3&&cii.fi<2);
	abo[3]=(pii.fi!=2&&cii.fi!=2)||(pii.fi==2&&cii.fi<2);

	rh[0]=pii.se==1||cii.se==0;

	if(abo[0]+abo[1]+abo[2]+abo[3]==0) {
		cout<<"IMPOSSIBLE";
		return;
	}

	print_set(abo,rh);
}

void solve() {
	if(p1=="?") find_parent(p2,c);
	else cout<<p1;
	cout<<' ';
	if(p2=="?") find_parent(p1,c);
	else cout<<p2;
	cout<<' ';
	if(c=="?") find_child(p1,p2);
	else cout<<c;
	cout<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;1;++i) {
		cin>>p1>>p2>>c;
		if(p1=="E") break;
		cout<<"Case "<<i<<": ";
		solve();
	}
}
