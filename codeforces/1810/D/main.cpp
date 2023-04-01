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

int t,q,type,a,b,n;

void solve() {
	cin>>q;
	ll l=-1,r=-1;
	while(q--) {
		cin>>type;
		if(type==1) {
			cin>>a>>b>>n;
			ll curr_l=1LL*max(0,n-2)*(a-b)+a+1,curr_r=1LL*max(0,n-1)*(a-b)+a;
			if(n==1) curr_l=1;
			if(l==-1) l=curr_l,r=curr_r,cout<<'1'<<" \n"[q==0];
			else if(curr_r<l||curr_l>r) cout<<'0'<<" \n"[q==0];
			else l=max(l,curr_l),r=min(r,curr_r),cout<<'1'<<" \n"[q==0];
			//cout<<"here:"<<l<<' '<<r<<'\n';
		} else if(type==2) {
			cin>>a>>b;
			if(l==-1) {cout<<"-1"<<" \n"[q==0]; continue; }
			ll test_l=max(1LL,(ll)ceil(1.0*(l-a)/(a-b))+1),test_r=max(1LL,(ll)ceil(1.0*(r-a)/(a-b))+1);
			if(max(0LL,test_l-1)*(a-b)+a<l) ++test_l;
			if(max(0LL,test_r-1)*(a-b)+a<r) ++test_r;
			if(test_l==test_r) cout<<test_l<<" \n"[q==0];
			else cout<<"-1"<<" \n"[q==0];
		}
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
