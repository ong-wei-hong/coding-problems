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

int t,k,q,m;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(scanf("%d %d %d", &k, &q, &m)!=EOF) {
		if(k==q) {
			printf("Illegal state\n");
			continue;
		}
		int qv=q%8,qh=q/8,kv=k%8,kh=k/8,mv=m%8,mh=m/8;
		if(m==k||m==q) {
			printf("Illegal move\n");
			continue;
		}else if(qv==mv) {
			if(mv==kv&&qh<kh!=mh<kh) {
				printf("Illegal move\n");
				continue;
			}
		} else if(qh==mh) {
			if(mh==kh&&qv<kv!=mv<kv) {
				printf("Illegal move\n");
				continue;
			}
		} else {
			printf("Illegal move\n");
			continue;
		}

		if((mv==kv&&abs(mh-kh)==1)||(mh==kh&&abs(mv-kv)==1)) {
			printf("Move not allowed\n");
			continue;
		}

		if((k==0||k==7||k==56||k==63)&&abs(kv-mv)==1&&abs(kh-mh)==1)
			printf("Stop\n");
		else
			printf("Continue\n");
	}
}
