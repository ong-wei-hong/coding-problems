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
string line;
char pieces[]{'K','Q','R','B','N'};

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	vector<vector<ii>> white_map(26),black_map(26);
	getline(cin,line);
	forn(i,8) {
		getline(cin,line);
		forn(j,8) {
			char piece=line[2+4*j];
			if(piece!=':'&&piece!='.') 
				if('a'<=piece&&piece<='z')black_map[piece-'a'].eb(7-i,j);
				else white_map[piece-'A'].eb(7-i,j);
		}
		getline(cin,line);
	}
	cout<<"White: ";
	bool first=1;
	for(char c: pieces) {
		sort(all(white_map[c-'A']));
		for(auto p: white_map[c-'A']) {
			if(first) first=0;
			else cout<<',';
			cout<<c<<char(p.se+'a')<<(p.fi+1);
		}
	}
	sort(all(white_map['P'-'A']));
	for(auto p: white_map['P'-'A']) {
		if(first) first=0;
		else cout<<',';
		cout<<char(p.se+'a')<<(p.fi+1);
	}	
	cout<<"\nBlack: ";
	first=1;
	for(char c: pieces) {
		for(auto p: black_map[c-'A']) {
			if(first)first=0;
			else cout<<',';
			cout<<c<<char(p.se+'a')<<(p.fi+1);
		}
	}
	for(auto p:black_map['P'-'A']) {
		if(first) first=0;
		else cout<<',';
		cout<<char(p.se+'a')<<(p.fi+1);
	}
	cout<<'\n';
}
