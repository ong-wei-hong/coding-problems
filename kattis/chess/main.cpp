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

int t,moves[4];
char a,b,c,d;

void solve() {
	cin>>a>>b>>c>>d;
	int xr=a-'A',xc=b-'1',yr=c-'A',yc=d-'1',l=0;
	if((xr+xc)%2!=(yr+yc)%2) {
		cout<<"Impossible\n";
		return;
	}
	if(xr==yr&&xc==yc) {
		cout<<"0 "<<a<<' '<<b<<'\n';
		return;
	}

	if((xr-xc==yr-yc)||(xr+xc==yr+yc)) {
		cout<<"1 "<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
		return;
	}

	if((xr+xc)%2) {
		if(xr+xc!=7) {
			forn(i,8) if(7-2*i==xr-xc) {
				moves[2*l]=7-i;
				moves[2*l+1]=i;
				break;
			}
			++l;
		}

		if(yr+yc!=7) {
			forn(i,8) if(7-2*i==yr-yc) {
				moves[2*l]=7-i;
				moves[2*l+1]=i;
				break;
			}
			++l;
		}
	} else {
		if(xr-xc!=0) {
			forn(i,8) if(2*i==xr+xc) {
				moves[2*l]=i;
				moves[2*l+1]=i;
				break;
			}
			++l;
		}

		if(yr-yc!=0) {
			forn(i,8) if(2*i==yr+yc) {
				moves[2*l]=i;
				moves[2*l+1]=i;
				break;
			}
			++l;
		}
	}

	cout<<(l+1)<<' '<<a<<' '<<b<<' ';
	forn(i,l) cout<<char('A'+moves[2*i])<<' '<<(1+moves[2*i+1])<<' ';
	cout<<c<<' '<<d<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
