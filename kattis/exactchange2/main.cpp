#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int, int>>
#define pq std::priority_queue

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define LSOne(S) ((S)&-(S))

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair

template<typename T> using ost = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const ll MOD = 998244353;
const ld prec = .00000000001;
const int inf = 1e9 + 10;
const ll linf = 1e18 + 10;

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

void cin_ignore() {
	cin.ignore(256,'\n');
}

class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int n) {
		p.resize(n); forn(i,n) p[i]=i;
		rank.assign(n,0);
		setSize.assign(n,1);
		numSets=n;
	}

	int findSet(int i) { return (p[i] == i) ? i : (p[i]=findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	int numDisjointSets() { return numSets; }
	int sizeOfSet(int i) { return setSize[findSet(i)]; }

	int unionSet(int i, int j) {
		if(isSameSet(i,j)) return findSet(i);
		int x=findSet(i),y=findSet(j);
		if(rank[x]>rank[y]) swap(x,y);
		p[x]=y;
		if(rank[x]==rank[y]) ++rank[y];
		setSize[y]+=setSize[x];
		--numSets;
		return y;
	}
};

class FenwickTree {
private:
	vi ft;
public:
	FenwickTree(int n) { ft.assign(n+1,0); }

	void build(const vll &f) {
		int m=(int)f.size()-1;
		ft.assign(m+1,0);
		for(int i=1;i<=m;++i) {
			ft[i]+=f[i];
			if(i+LSOne(i)<=m) ft[i+LSOne(i)]+=ft[i];
		}
	}

	ll rsq(int j) {
		ll sum=0;
		for(;j;j-=LSOne(j)) sum+=ft[j];
		return sum;
	}

	ll rsq(int i, int j) { return rsq(j)-rsq(i-1); }

	void update(int i, int v) {
		for(;i<(int)ft.size();i+=LSOne(i)) ft[i]+=v;
	}

	int select(ll k) {
		int lo=1,hi=ft.size()-1;
		for(int i=0;i<30;++i) {
			int mid=(lo+hi)/2;
			(rsq(1,mid)<k)?(lo=mid):(hi=mid);
		}
		return hi;
	}
};

class RUPQ {
private:
	FenwickTree ft;
public:
	RUPQ(int m) : ft(FenwickTree(m)) {}
	void range_update(int ui, int uj, int v) {
		ft.update(ui,v);
		ft.update(uj+1,-v);
	}
	ll point_query(int i) { return ft.rsq(i); }
};

class RURQ {
private:
	FenwickTree purq;
	RUPQ rupq;
public:
	RURQ(int m) : purq(FenwickTree(m)), rupq(RUPQ(m)) {}
	void range_update(int ui, int uj, int v) {
		rupq.range_update(ui,uj,v);
		purq.update(ui,(ui-1)*v);
		purq.update(uj+1,-v*uj);
	}
	ll rsq(int i) {
		return rupq.point_query(i)*i-purq.rsq(i);
	}
	ll rsq(int i, int j) { return rsq(j) - rsq(i-1); }
};

class SegmentTree {
private:
	int n;
	vi A, st, lazy;

	int l(int p) { return p<<1; }
	int r(int p) { return (p<<1)+1; }

	int conquer(int a, int b) {
		if(a==-1) return b;
		if(b==-1) return a;
		return min(a,b);
	}

	void build(int p, int L, int R) {
		if(L == R) st[p]=A[L];
		else {
			int m=(L+R)/2;
			build(l(p),L,m);
			build(r(p),m+1,R);
			st[p]=conquer(st[l(p)],st[r(p)]);
		}
	}

	void propagate(int p, int L, int R) {
		if (lazy[p]!=-1) {
			st[p]=lazy[p];
			if(L!=R) lazy[l(p)]=lazy[r(p)]=lazy[p];
			else A[L]=lazy[p];
			lazy[p]=-1;
		}
	}

	int RMQ(int p, int L, int R, int i, int j) {
		propagate(p, L, R);
		if(i>j) return -1;
		if((L>=i)&&(R<=j)) return st[p];
		int m=(L+R)/2;
		return conquer(RMQ(l(p),L,m,i,min(m,j)),
			       RMQ(r(p),m+1,R,max(i,m+1),j));
	}

	void update(int p, int L, int R, int i, int j, int val) {
		propagate(p,L,R);
		if(i>j) return;
		if((L>=i)&&(R<=j)) {
			lazy[p]=val;
			propagate(p,L,R);
		}
		else {
			int m=(L+R)/2;
			update(l(p),L,m,i,min(m,j),val);
			update(r(p),m+1,R,max(i,m+1),j,val);
			int lsubtree=(lazy[l(p)]!=-1)?lazy[l(p)]:st[l(p)];
			int rsubtree=(lazy[r(p)]!=-1)?lazy[r(p)]:st[r(p)];
			st[p]=(lsubtree<=rsubtree)?st[l(p)]:st[r(p)];
		}
	}

public:
	SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}

	SegmentTree(const vi &initialA): SegmentTree((int)initialA.size()) {
		A = initialA;
		build(1,0,n-1);
	}

	void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

	int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
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

int n,value,coin,dp[10001];

void solve() {
	cin>>value;
	memset(dp,0,sizeof(dp));
	cin>>n;
	forn(_,n) {
		cin>>coin;
		for(int i=10000-coin;i>=0;--i) if(dp[i]) {
			if(dp[i+coin]==0)dp[i+coin]=dp[i]+1;
			dp[i+coin]=min(dp[i+coin],dp[i]+1);
		}
		dp[coin]=1;
	}
	if(value==0) {
		cout<<"0 0\n";
		return;
	}
	for(int i=value;1;++i) if(dp[i]) {
		cout<<i<<' '<<dp[i]<<'\n';
		return;
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
