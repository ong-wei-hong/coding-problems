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
string m[10] {"xxx.xxx","..x..x.","x.xxx.x","x.xx.xx",".xxx.x.","xx.x.xx","xx.xxxx","x.x..x.","xxxxxxx","xxxx.xx"},a[7];
ii c[7] {{0,1},{1,0},{1,4},{3,2},{4,0},{4,4},{6,1}};

int get(int i) {
	forn(j,10) {
		bool valid=1;
		forn(k,7) valid&=a[c[k].fi][i+c[k].se]==m[j][k];
		if(valid) return j;
	}
	return -1;
}

void solve() {
	int x=0,y=0,*z=&x;
	for(int i=0;i<a[0].size();i+=6) {
		int j=get(i);
		if(j==-1) z=&y;
		else *z=10*(*z)+j;
	}
	vi v;
	x+=y;
	while(x) {
		v.pb(x%10);
		x/=10;
	}
	bool f=1;
	for(auto it=v.rbegin();it!=v.rend();++it) {
		if(f) f=0;
		else cout<<'.';

		if(m[*it][0]=='x'||m[*it][1]=='x') cout<<'x';
		else cout<<'.';

		forn(i,3) cout<<m[*it][0];

		if(m[*it][0]=='x'||m[*it][2]=='x') cout<<'x';
		else cout<<'.';
	}
	cout<<'\n';

	forn(i,2) {
		f=1;
		for(auto it=v.rbegin();it!=v.rend();++it) {
			if(f) f=0;
			else cout<<'.';

			cout<<m[*it][1];
			forn(j,3) cout<<'.';
			cout<<m[*it][2];
		}
		cout<<'\n';
	}

	f=1;
	for(auto it=v.rbegin();it!=v.rend();++it) {
		if(f) f=0;
		else cout<<'.';
		if(m[*it][1]=='x'||m[*it][3]=='x'||m[*it][4]=='x') cout<<'x';
		else cout<<'.';
		forn(i,3) cout<<m[*it][3];
		if(m[*it][2]=='x'||m[*it][3]=='x'||m[*it][5]=='x') cout<<'x';
		else cout<<'.';
	}
	cout<<'\n';
	forn(i,2) {
		f=1;
		for(auto it=v.rbegin();it!=v.rend();++it) {
			if(f) f=0;
			else cout<<'.';

			cout<<m[*it][4];
			forn(j,3) cout<<'.';
			cout<<m[*it][5];
		}
		cout<<'\n';
	}
	f=1;
	for(auto it=v.rbegin();it!=v.rend();++it) {
		if(f) f=0;
		else cout<<'.';
		if(m[*it][4]=='x'||m[*it][6]=='x') cout<<'x';
		else cout<<'.';
		forn(i,3)
			cout<<m[*it][6];
		if(m[*it][5]=='x'||m[*it][6]=='x') cout<<'x';
		else cout<<'.';
	}
	cout<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(auto &s: a) cin>>s;
	solve();
}
