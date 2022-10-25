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

int ufds_find_set(vi& ufds, int i){
	if(ufds[i]==i) return i;
	return ufds[i]=ufds_find_set(ufds,ufds[i]);
}

void ufds_union_set(vi& ufds, vi& rank, int i, int j){
	i = ufds_find_set(ufds,i);
	j = ufds_find_set(ufds,j);
	if(i==j) return;
	if(rank[i]>rank[j]) ufds[j]=i;
	else ufds[i]=j,++rank[j];
}

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

int t,n,q,l,r;

void solve() {
	cin>>n>>q;
	vi v(n);
	for(auto& i: v) cin>>i;
	cin>>l>>r;
	vll prefix_sum(r-l+2), prefix_xor(r-l+2);
	forn(i,r-l+1) prefix_sum[i+1]=prefix_sum[i]+v[l+i-1],prefix_xor[i+1]=prefix_xor[i]^v[l+i-1];
	int ans_l=1,ans_r=r-l+1;
	ll f=prefix_sum[r-l+1]-prefix_xor[r-l+1];
	for(int i=1;i<=r-l+1;++i) {
		if(prefix_sum[r-l+1]-prefix_sum[i-1]-prefix_xor[r-l+1]+prefix_xor[i-1]<f) continue;
		int lb=i,rb=r-l+1;
		while(lb<=rb) {
			int mid=(lb+rb)/2;
			ll curr=prefix_sum[mid]-prefix_sum[i-1]-(prefix_xor[mid]^prefix_xor[i-1]);
			if(curr<f) lb=mid+1;
			else{
				if(mid-i+1<ans_r-ans_l+1) ans_l=i,ans_r=mid;
				rb=mid-1;
			}
		}
	}
	cout<<ans_l+l-1<<' '<<ans_r+l-1<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
