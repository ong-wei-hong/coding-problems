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

int n;
string s;
vi v;

int get_d_in_m(int m) {
	if(m==0) return 0;
	if(m==2) return 28;
	if(m<8) return 30+m%2;
	return 31-m%2;
}

void solve() {
}

int sdate() {
	int ans=0;
	forn(i,10) ans+=get_d_in_m(i);
	return ans+27;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	v.resize(n);
	forn(i,n) {
		cin>>s>>s;
		int m=stoi(s.substr(0,2)),d=stoi(s.substr(3,2));
		forn(j,m) d+=get_d_in_m(j);
		v[i]=d-1;
	}
	int ans,dist1=0,dist2=999;
	forn(d,365) {
		int curr_dist1=999;
		for(auto i: v) 
			curr_dist1=min(curr_dist1,(d+365-i)%365);
		if((curr_dist1==dist1&&((d+365-sdate())%365<dist2))||curr_dist1>dist1) 
			ans=d,dist1=curr_dist1,dist2=(d+365-sdate())%365;
	}
	int m=0;
	while(ans>=get_d_in_m(m)) ans-=get_d_in_m(m),++m;
	cout<<setfill('0')<<setw(2)<<m<<'-'<<setfill('0')<<setw(2)<<ans+1<<'\n';
}
