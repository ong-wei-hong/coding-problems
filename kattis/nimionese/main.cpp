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

#define FORN(i, n) for(int i=0; i<int(n); ++i)
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define LSONE(S) ((S)&-(S))
#define UNIQUE(v) (v).resize(unique(ALL(v))-(v).begin())

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair

// max flow stuff
typedef tuple<int, ll, ll> edge;
typedef tuple<int, ll, ll, ll> edge2;

template<typename T> using ost = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const ll MOD = 998244353;
const ld PREC = .00000000001;
const int INF = 1e9 + 10;
const ll LINF = 1e18 + 10;

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

void cin_ignore() {
	cin.ignore(256,'\n');
}

int Aug(int L, vi &vis, vi &match, vector<vi> &AL) {
	if(vis[L]) return 0;
	vis[L]=1;
	for(auto &R: AL[L])
		if((match[R]==-1)||(Aug(match[R], vis, match, AL))) {
			match[R]=L;
			return 1;
		}
	return 0;
}

int MCBM(int Vleft, int V, vector<vi> &AL, vi &match) {
	unordered_set<int> freeV;
	vi vis;
	for(int L=0;L<Vleft;++L) freeV.insert(L);
	match.assign(V,-1);
	int ans=0;
	for(int L=0;L<Vleft;++L) {
		vi candidates;
		for(auto &R: AL[L]) if(match[R] == -1) candidates.pb(R);
		if((int)candidates.size()>0) {
			++ans;
			freeV.erase(L);
			int a = rand()%(int)candidates.size();
			match[candidates[a]]=L;
		}
	}
	for(auto &f: freeV) {
		vis.assign(Vleft,0);
		ans+=Aug(f, vis, match, AL);
	}

	return ans;
}

int MCBM(int Vleft, int V, vector<vi> &AL) {
	vi match(V,-1);
	return MCBM(Vleft,V,AL,match);
}

class MinCostMaxFlow {
private:
	int V;
	ll total_cost;
	vector<edge2> EL;
	vector<vi> AL;
	vll d;
	vi last, vis;

	bool SPFA(int s, int t) {
		d.assign(V,INF); d[s]=0;vis[s]=1;
		queue<int> q({s});
		while(!q.empty()) {
			int u=q.front(); q.pop(); vis[u]=0;
			for(auto &idx : AL[u]) {
				auto &[v,cap,flow,cost] = EL[idx];
				if((cap-flow > 0) && (d[v] > d[u] + cost)) {
					d[v] = d[u]+cost;
					if(!vis[v]) q.push(v), vis[v]=1;
				}
			}
		}
		return d[t] != INF;
	}

	ll DFS(int u, int t, ll f = INF) {
		if ((u == t) || (f == 0)) return f;
		vis[u] = 1;
		for(int &i = last[u]; i< (int) AL[u].size(); ++i) {
			auto &[v, cap, flow, cost] = EL[AL[u][i]];
			if(!vis[v] && d[v] == d[u]+cost) {
				if(ll pushed = DFS(v, t, min(f, cap-flow))) {
					total_cost += pushed * cost;
					flow += pushed;
					auto &[rv, rcap, rflow, rcost] = EL[AL[u][i]^1];
					rflow -= pushed;
					vis[u]=0;
					return pushed;
				}
			}
		}
		vis[u]=0;
		return 0;
	}

public:
	MinCostMaxFlow(int initialV) : V(initialV), total_cost(0) {
		EL.clear();
		AL.assign(V, vi());
		vis.assign(V, 0);
	}

	void add_edge(int u, int v, ll w, ll c, bool directed=true) {
		if(u==v) return;
		EL.eb(v, w, 0, c);
		AL[u].pb(EL.size()-1);
		EL.eb(u,0,0,-c);
		AL[v].pb(EL.size()-1);
		if(!directed) add_edge(v,u,w,c);
	}

	pair<ll, ll> mcmf(int s, int t) {
		ll mf=0;
		while(SPFA(s, t)) {
			last.assign(V, 0);
			while(ll f = DFS(s, t)) mf += f;
		}
		return {mf, total_cost};
	}
};


class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int n) {
		p.resize(n); FORN(i,n) p[i]=i;
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
			if(i+LSONE(i)<=m) ft[i+LSONE(i)]+=ft[i];
		}
	}

	ll rsq(int j) {
		ll sum=0;
		for(;j;j-=LSONE(j)) sum+=ft[j];
		return sum;
	}

	ll rsq(int i, int j) { return rsq(j)-rsq(i-1); }

	void update(int i, int v) {
		for(;i<(int)ft.size();i+=LSONE(i)) ft[i]+=v;
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
	vi A,lazy;
      	vii st; // (value, index)

	int l(int p) { return p<<1; }
	int r(int p) { return (p<<1)+1; }

	ii conquer(ii a, ii b) {
		if(a.se<0) return b;
		if(b.se<0) return a;
		return a.fi >= b.fi ? a : b;
	}

	void build(int p, int L, int R) {
		if(L == R) st[p]=mp(A[L],L);
		else {
			int m=(L+R)/2;
			build(l(p),L,m);
			build(r(p),m+1,R);
			st[p]=conquer(st[l(p)],st[r(p)]);
		}
	}

	void propagate(int p, int L, int R) {
		if (lazy[p]!=-1) {
			st[p]=mp(lazy[p],L);
			if(L!=R) lazy[l(p)]=lazy[r(p)]=lazy[p];
			else A[L]=lazy[p];
			lazy[p]=-1;
		}
	}

	ii RMQ(int p, int L, int R, int i, int j) {
		propagate(p, L, R);
		if(i>j) return mp(-1,-1);
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

			ii lsubtree=(lazy[l(p)]!=-1)?mp(lazy[l(p)],L):st[l(p)];
			ii rsubtree=(lazy[l(p)]!=-1)?mp(lazy[r(p)],m+1):st[r(p)];
			st[p]=conquer(lsubtree,rsubtree);
		}
	}

public:
	SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}

	SegmentTree(const vi &initialA): SegmentTree((int)initialA.size()) {
		A = initialA;
		build(1,0,n-1);
	}

	void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

	ii RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};

class SparseTable {
	private:
		vi A, P2, L2;
		vector<vi> SpT;

		int conquer(int i, int j) {
			return A[i] <= A[j] ? i : j;
		}
	public:
		SparseTable() {}
		SparseTable(vi &initialA) {
			A = initialA;
			int n = (int)A.size();
			int L2_n = (int) log2(n)+1;
			P2.assign(L2_n,0);
			L2.assign(1<<L2_n,0);
			FORN(i,L2_n+1) {
				P2[i]=(1<<i);
				L2[(1<<i)]=i;
			}
			for(int i=2;i<P2[L2_n];++i) if(L2[i]==0) L2[i]=L2[i-1];

			SpT=vector<vi>(L2[n]+1,vi(n));
			for(int j=0;j<n;++j) SpT[0][j]=j;

			for(int i=1;P2[i]<=n;++i)
				for(int j=0;j+P2[i]-1<n;++j) {
					int x=SpT[i-1][j];
					int y=SpT[i-1][j+P2[i-1]];
					SpT[i][j]=conquer(x,y);
				}
		}

		int RMQ(int i,int j) {
			int k=L2[j-i+1];
			int x=SpT[k][i];
			int y=SpT[k][j-P2[k]+1];
			return conquer(x,y);
		}
};

class MaxFlow {
private:
	int V;
	vector<edge> EL;
	vector<vi> AL;
	vi d,last;
	vii p;

	bool BFS(int s,int t) {
		d.assign(V,-1); d[s]=0;
		queue<int> q({s});
		p.assign(V,{-1,-1}); // predecessor, edge index
		while(!q.empty()) {
			int u=q.front(); q.pop();
			if(u==t) break;
			for(auto &idx: AL[u]) {
				auto &[v,cap,flow]=EL[idx];
				if((cap-flow>0)&&(d[v]==-1))
					d[v]=d[u]+1,q.push(v),p[v]={u,idx};
			}
		}
		return d[t]!=-1;
	}

	ll send_one_flow(int s,int t, ll f=LINF) {
		if(s==t) return f;
		auto &[u,idx]=p[t];
		auto &cap=get<1>(EL[idx]),&flow=get<2>(EL[idx]);
		ll pushed=send_one_flow(s,u,min(f,cap-flow));
		flow+=pushed;
		auto &rflow=get<2>(EL[idx^1]);
		rflow-=pushed;
		return pushed;
	}

	ll DFS(int u,int t,ll f=LINF) {
		if((u==t)||(f==0)) return f;
		for(int &i = last[u];i<(int)AL[u].size();++i) {
			auto &[v,cap,flow]=EL[AL[u][i]];
			if(d[v]!=d[u]+1) continue;
			if(ll pushed=DFS(v,t,min(f,cap-flow))) {
				flow += pushed;
				auto &rflow=get<2>(EL[AL[u][i]^1]);
				rflow-=pushed;
				return pushed;
			}
		}
		return 0;
	}

public:
	MaxFlow(int initialV) : V(initialV) {
		EL.clear();
		AL.assign(V,vi());
	}

	void add_edge(int u,int v,ll w, bool directed=true) {
		if(u==v) return;
		EL.eb(v,w,0);
		AL[u].pb(EL.size()-1);
		EL.eb(u,directed?0:w,0);
		AL[v].pb(EL.size()-1);
	}

	ll edmonds_karp(int s,int t) {
		ll mf=0;
		while(BFS(s,t)) {
			ll f=send_one_flow(s,t);
			if(f==0) break;
			mf+=f;
		}
		return mf;
	}

	ll dinic(int s,int t) {
		ll mf=0;
		while(BFS(s,t)) {
			last.assign(V,0);
			while(ll f=DFS(s,t))
				mf+=f;
		}
		return mf;
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

string s,cons="bcdgknpt";

char f(char c) {
	int dist=100,ans;
	c=tolower(c);
	for(auto i: cons) if(abs(i-c)<dist) dist=abs(i-c),ans=i;
	return ans;
}

char g(char c) {
	string t="aou";
	c=tolower(c);
	int dist=100,ans;
	for(auto i: t) if(abs(i-c)<dist) dist=abs(i-c),ans=i;
	return ans;
}

void solve() {
	int i=0;
	char c;
	bool fi=1;
	while(i<s.size()) {
		if(i==0) {
			c=f(tolower(s[0]));
			if('A'<=s[0]&&s[0]<='Z') s[0]=c-'a'+'A';
			else s[0]=c;
		}

		for(;i<s.size()&&s[i]!='-';++i) {
			if(!fi&&cons.find(tolower(s[i]))!=-1) s[i]=c;
			cout<<s[i];
		}

		++i;
		fi=0;
	}

	if(cons.find(tolower(s[s.size()-1]))!=-1) cout<<g(tolower(s[s.size()-1]))<<'h';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>s) solve(),cout<<' ';
	cout<<'\n';
}
