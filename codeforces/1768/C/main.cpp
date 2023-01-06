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
		if(y&1) z*=x;
		x=mul(x,x);
		y>>=1;
	}
	return z;
}

bool prime(ll x) {
	for(ll i=2;i*i<=x;++i)
		if(x%i==0) return false;
	return true;
}

int t,n,mini[2];
vii a,p;
vector<pair<bool,bool>> v;

void solve() {
	cin>>n;
	a.resize(n);
	p.resize(n);
	v.resize(n);
	for(auto& i: v) i=mp(1,1);
	forn(i,n) a[i].se=i,cin>>a[i].fi,--a[i].fi;
	sort(all(a));

	mini[0]=mini[1]=0;
	for(auto& [target, index]: a) {
		int i;
		if(v[target].fi) v[target].fi=0,i=0;
		else if(v[target].se) v[target].se=0,i=1;
		else {
			cout<<"NO\n";
			return;
		}

		if(i==0) {
			p[index].fi=target;
			while(mini[1]<=target&&!v[mini[1]].se) ++mini[1];
			if(mini[1]>target) {
				cout<<"NO\n";
				return;
			}
			p[index].se=mini[1];
			v[mini[1]].se=0;
		} else {
			p[index].se=target;
			while(mini[0]<=target&&!v[mini[0]].fi) ++mini[0];
			if(mini[0]>target) {
				cout<<"NO\n";
				return;
			}
			p[index].fi=mini[0];
			v[mini[0]].fi=0;
		}
	}

	cout<<"YES\n";
	forn(i,n) cout<<p[i].fi+1<<' ';
	cout<<'\n';
	forn(i,n) cout<<p[i].se+1<<' ';
	cout<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
