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
#define eb emplace_back #define mp make_pair

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
string b[3];

bool check(char c) {
	forn(i,3)
		if(b[i][0]==b[i][1]&&b[i][1]==b[i][2]&&b[i][2]==c) return 1;
		else if(b[0][i]==b[1][i]&&b[1][i]==b[2][i]&&b[2][i]==c) return 1;
	return (b[0][0]==b[1][1]&&b[1][1]==b[2][2]&&b[2][2]==c)||(b[2][0]==b[1][1]&&b[1][1]==b[0][2]&&b[0][2]==c);
}

void solve() {
	forn(i,3) cin>>b[i];
	int x=0,o=0;
	forn(i,3) forn(j,3) x+=(b[i][j]=='X'),o+=(b[i][j]=='O');
	bool x_win=check('X'),o_win=check('O');
	if((o>x)||
			(o<x-1)||
			(x_win&&o_win)||
			(x_win&&o==x)||
			(o_win&&o<x)) {
		cout<<"no\n";
	} else cout<<"yes\n";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
