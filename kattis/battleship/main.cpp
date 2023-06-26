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

int t,w,h,n;
ii orders[2000];
string map_one[30],map_two[30];

void solve() {
	cin>>w>>h>>n;
	int f=0,s=0;
	for(int i=h-1;i>=0;--i) {
		cin>>map_one[i];
		for(auto c: map_one[i]) f+=(c=='#');
	}
	for(int i=h-1;i>=0;--i) {
		cin>>map_two[i];
		for(auto c: map_two[i]) s+=(c=='#');
	}
	forn(i,n) cin>>orders[i].fi>>orders[i].se;

	bool first=1,end=0;
	forn(i,n) {
		//forn(i,h) cout<<map_one[i]<<'\n';
		//cout<<"=========\n";
		//forn(i,h) cout<<map_two[i]<<'\n';
		//cout<<'\n';

		string *m=map_one;
		int *num_alive=&f;
		if(first) m=map_two,num_alive=&s;

		int x=orders[i].fi,y=orders[i].se;
		if(m[y][x]=='#') {
			--(*num_alive);
			m[y][x]='_';
			if((*num_alive)==0) end=1,first=!first;
		} else first=!first;
		//m[y][x]='x';
		
		if(end&&first) {
			if(!f&&!s) cout<<"draw\n";
			else {
				cout<<"player ";
				if(f) cout<<"one";
				else cout<<"two";
				cout<<" wins\n";
			}
			return;
		}
	}
	cout<<"draw\n";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
