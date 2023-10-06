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

int t,n,m;
vector<string> v;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	v.resize(n);
	for(auto &s: v) cin>>s;

	queue<ii> q;
	forn(i,n) forn(j,m) 
		if(v[i][j]=='.') q.emplace(i,j);

	forn(i,n) {
		if(v[i][0]=='T') v[i][0]='1',q.emplace(i,0);
		if(v[i][m-1]=='T') v[i][m-1]='1',q.emplace(i,m-1);
	}

	forn(i,m) {
		if(v[0][i]=='T') v[0][i]='1',q.emplace(0,i);
		if(v[n-1][i]=='T') v[n-1][i]='1',q.emplace(n-1,i);
	}

	int x=0;

	while(!q.empty()) {
		auto p=q.front();
		q.pop();

		int di[4]{0,0,-1,1},dj[4]{1,-1,0,0};
		forn(i,4) {
			auto t=p;
			t.fi+=di[i],t.se+=dj[i];
			if(0<=t.fi&&t.fi<n&&0<=t.se&&t.se<m&&v[t.fi][t.se]=='T') {
				if(v[p.fi][p.se]=='.') v[t.fi][t.se]='1';
				else v[t.fi][t.se]=v[p.fi][p.se]+1;
				x=max(x,v[t.fi][t.se]-'0');
				q.push(t);
			}
		}
	}

	string space=".";
	if(x>9) space="..";
	for(auto &s: v) {
		for(auto c: s)
			if(c=='.') cout<<space<<c;
			else {
				int i=c-'0';
				if(i<10) cout<<space<<c;
				else cout<<'.'<<i;
			}
		cout<<'\n';
	}
}
