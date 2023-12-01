#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
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

int t,a[1005]={3,8,11,32,35,56,59,64,67,118,121,208,211,216,219,622,625,712,715,720,723,744,747,896,899,986,989,2560,2563,2778,2781,3806,3809,3890,3893,4198,4201,4584,4587,5338,5341,5458,5461,5962,5965,8642,8645,12084,12087,12772,12775,13602,13605,14012,14015,17336,17339,18016,18019,19310,19313,20940,20943,26374,26377,29320,29323,38154,38157,42662,42665,43502,43505,45930,45933,49686,49689,60066,60069,64476,64479,72448,72451,83956,83959,91046,91049,93740,93743,96310,96313,118766,118769,123806,123809,143434,143437,147712,147715,154866,154869,170090,170093,187820,187823,209752,209755,244800,244803,273474,273477,347428,347431,382530,382533,402720,402723,467274,467277,543812,543815,561334,561337,580884,580887,607694,607697,665034,665037,686696,686699,693306,693309,816300,816303,960620,960623,960964,960967,1024258,1024261,1157516,1157519,1340720,1340723,1377504,1377507,1412330,1412333,1454878,1454881,1488314,1488317,1608896,1608899,1907342,1907345,1915204,1915207,1953088,1953091,2011552,2011555,2053088,2053091,2218520,2218523,2439860,2439863,2506800,2506803,2792760,2792763,2818000,2818003,3058974,3058977,3692938,3692941,3810186,3810189,3850764,3850767,4240946,4240949,5380204,5380207,5484644,5484647,5632196,5632199,6136490,6136493,6929080,6929083,7019280,7019283,7163844,7163847,7339412,7339415,8299624,8299627,9702450,9702453,10000910,10000913,11404634,11404637,13368688,13368691,13509604,13509607,13750138,13750141,15095790,15095793,16166924,16166927,16409144,16409147,17105420,17105423,17412348,17412351,17820008,17820011,20007958,20007961,20693774,20693777,22045460,22045463,23380094,23380097,24789334,24789337,25126678,25126681,26647980,26647983,27683252,27683255,27781826,27781829,28640628,28640631,33645474,33645477,36104218,36104221,36190982,36190985,36607498,36607501,36830424,36830427,38880354,38880357,40010700,40010703,42600652,42600655,46883338,46883341,47261042,47261045,50441582,50441585,50806108,50806111,51326550,51326553,63270628,63270631,73376298,73376301,79246954,79246957,85507614,85507617,86494788,86494791,87659372,87659375,93188572,93188575,102490320,102490323,111387292,111387295,117666362,117666365,125481924,125481927,125946452,125946455,129257606,129257609,131533502,131533505,148061544,148061547,154708884,154708887,156257698,156257701,164235208,164235211,174422902,174422905,177543326,177543329,200688798,200688801,203517204,203517207,227993998,227994001,235532762,235532765,239063820,239063823,241476986,241476989,251732672,251732675,279478702,279478705,281430472,281430475,294129388,294129391,300664758,300664761,309796952,309796955,315713182,315713185,343273582,343273585,364007276,364007279,367324042,367324045,373016576,373016579,385477086,385477089,405738568,405738571,442967366,442967369,480451560,480451563,519983304,519983307,536597756,536597759,629403140,629403143,713858034,713858037,739002982,739002985,809065744,809065747,813583138,813583141,822228058,822228061,830259270,830259273,834828324,834828327,916215504,916215507,978364206,978364209,1000000005},n;

void solve() {
	cin>>n;
	for(auto i: a) if(i==n) {
		cout<<"Bob\n";
		return;
	}
	cout<<"Alice\n";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
