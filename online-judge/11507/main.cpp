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

int t,L;
string s;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(1) {
		cin>>L;
		if(L==0) break;
		int x=1,y=0,z=0;
		while(--L) {
			cin>>s;
			if(s=="No") continue;
			int i=1-2*(s[0]=='-');
			bool is_y=s[1]=='y';
			if(x) {
				if(is_y) y=x*i;
				else z=x*i;
				x=0;
			} else if (y) {
				if(is_y) {
					x=-1*y*i;
					y=0;
				}
			} else if (z) {
				if(!is_y) {
					x=-1*z*i;
					z=0;
				}
			}
		}
		cout<<(x+y+z>0?'+':'-');
		if(x) cout<<'x';
		if(y) cout<<'y';
		if(z) cout<<'z';
		cout<<'\n';
	}
}
