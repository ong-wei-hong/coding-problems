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

int t,N,A[200000];
bool B[200000];

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>N>>t;
	forn(i,N) cin>>A[i];
	ll sum=0;
	int i=0;
	switch(t) {
		case 1: cout<<"7\n"; return 0;
		case 2: cout<<(A[0]>A[1]?"Bigger":(A[0]==A[1]?"Equal":"Smaller"))<<'\n'; return 0;
		case 3: sort(A,A+3); cout<<A[1]<<'\n'; return 0;
		case 4: cout<<accumulate(A, A+N, 0LL)<<'\n'; return 0;
		case 5:
			forn(i,N) if(!(A[i]%2)) sum+=A[i];
			cout<<sum<<'\n';
			return 0;
		case 6: forn(i,N) cout<<char('a'+(A[i]%26));
			cout<<'\n';
			return 0;
		case 7:
			while(1) {
				if(B[i]) {
					cout<<"Cyclic\n";
					return 0;
				}
				B[i]=1;
				i=A[i];
				if(i>=N) {
					cout<<"Out\n";
					return 0;
				}
				if(i==N-1) {
					cout<<"Done\n";
					return 0;
				}
			}
	}
}
