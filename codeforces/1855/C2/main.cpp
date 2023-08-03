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

int t,n,a[20];

void solve() {
	cin>>n;
	forn(i,n) cin>>a[i];
	int pos,neg,maxi,mini;
	pos=neg=0;
	maxi=-20;
	mini=20;
	forn(i,n) pos+=(a[i]>0),neg+=(a[i]<0),maxi=max(a[i],maxi),mini=min(a[i],mini);
	
	int x=pos,y=neg;
	if(pos&&mini<0&&abs(mini)<abs(maxi)) x+=5;
	else if(neg&&maxi>0&&abs(maxi)<abs(mini)) y+=5;

	bool b=neg>0;
	vii ans;
	if(x<y) {
		b=1;
		int miniI;
		forn(i,n) if(a[i]==mini) miniI=i;
		while(abs(a[miniI])<abs(maxi)) ans.eb(miniI,miniI),a[miniI]+=a[miniI];
		forn(i,n) if(a[i]>0) ans.eb(i,miniI);
	} else {
		b=0;
		int maxiI;
		forn(i,n) if(a[i]==maxi) maxiI=i;
		while(abs(a[maxiI])<abs(mini)) ans.eb(maxiI,maxiI),a[maxiI]+=a[maxiI];
		forn(i,n) if(a[i]<0) ans.eb(i,maxiI);
	}

	cout<<ans.size()+n-1<<'\n';
	for(auto &p: ans) cout<<p.fi+1<<' '<<p.se+1<<'\n';
	if(b) forn(i,n-1) cout<<n-i-1<<' '<<n-i<<'\n';
	else forn(i,n-1) cout<<i+2<<' '<<i+1<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
