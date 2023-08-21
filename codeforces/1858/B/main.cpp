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

int t,n,m,d;
vi v,dp1,dp2;

void solve() {
	cin>>n>>m>>d;
	v.resize(m);
	for(auto &i: v) cin>>i;

	dp1.resize(m);
	dp1[0]=(v[0]-2)/d+2-(v[0]==1);
	for(int i=1;i<m;++i) dp1[i]=dp1[i-1]+(v[i]-v[i-1]-1)/d+1;

	dp2.resize(m);
	dp2[m-1]=(n-v[m-1])/d+1;
	for(int i=m-2;i>=0;--i) dp2[i]=dp2[i+1]+(v[i+1]-v[i]-1)/d+1;

	int ans1,ans2,curr;
	ans1=(v[1]-2)/d+1+dp2[1];
	ans2=1;

	for(int i=1;i<m-1;++i) {
		curr=dp1[i-1]+dp2[i+1]+(v[i+1]-v[i-1]-1)/d;
		if(curr<ans1) ans1=curr,ans2=0;
		ans2+=(curr==ans1);
	}

	curr=(n-v[m-2])/d+dp1[m-2];
	if(curr<ans1) ans1=curr,ans2=0;
	ans2+=(curr==ans1);

	cout<<ans1<<' '<<ans2<<'\n';

}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
