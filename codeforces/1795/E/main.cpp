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

int t,n;
vll h,dL,dR;

void solve() {
	cin>>n;
	h.resize(n),dL.resize(n),dR.resize(n);
	ll sum=0;
	for(auto& i: h) cin>>i,sum+=i;

	stack<ii> st;
	forn(i,n) {
		while(st.size()&&st.top().se>=h[i]+st.top().fi-i) st.pop();
		dL[i]=st.empty()?-1:st.top().fi;
		st.emplace(i,h[i]);
	}

	stack<ii> st1;
	for(int i=n-1;i>=0;--i) {
		while(st1.size()&&st1.top().se>=h[i]-st1.top().fi+i) st1.pop();
		dR[i]=st1.empty()?-1:st1.top().fi;
		st1.emplace(i,h[i]);
	}

	forn(i,n) 
		if(dL[i]==-1) dL[i]=(min(1LL*i,h[i])+1)*(2*h[i]-min(1LL*i,h[i]))/2;
		else dL[i]=dL[dL[i]]+(i-dL[i])*(2*h[i]-i+dL[i]+1)/2;

	for(int i=n-1;i>=0;--i)
		if(dR[i]==-1) dR[i]=min(h[i],1LL*n-i)*(2*h[i]-min(1LL*n-i,h[i])+1)/2;
		else dR[i]=dR[dR[i]]+(dR[i]-i)*(2*h[i]-dR[i]+i+1)/2;

	ll ans=LLONG_MAX;
	forn(i,n) ans=min(ans,sum-dL[i]-dR[i]+(h[i]<<1));
	cout<<ans<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
