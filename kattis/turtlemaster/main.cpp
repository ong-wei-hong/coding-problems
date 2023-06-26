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

int t,dx[4]{0,1,0,-1},dy[4]{1,0,-1,0},currD,x=7,y;
string m[8],action;

bool invalid(int x, int y) {
	return x<0||x>=8||y<0||y>=8;
}

void solve() {
	forn(i,8) cin>>m[i];
	cin>>action;
	for(char c: action) switch(c) {
		case 'F':
			x+=dx[currD],y+=dy[currD];
			if(invalid(x,y)||m[x][y]=='C'||m[x][y]=='I') {
				cout<<"Bug!\n";
				return;
			}
			break;
		case 'R':
			currD=(currD+1)%4;
			break;
		case 'L':
			currD=(currD+3)%4;
			break;
		case 'X':
			int nx=x+dx[currD],ny=y+dy[currD];
			if(invalid(nx,ny)||m[nx][ny]!='I') {
				cout<<"Bug!\n";
				return;
			}
			m[nx][ny]='.';
			break;
	}
	if(m[x][y]=='D') {
		cout<<"Diamond!\n";
	} else cout<<"Bug!\n";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}
