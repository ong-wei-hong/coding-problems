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

int t,n;
vi v;

void solve() {
	switch(t) {
		case 1:
			sort(all(v));
			for(int i=0,j=n-1;i<j;) {
				if(v[i]+v[j]==7777) {
					cout<<"Yes\n";
					return;
				} else if(v[i]+v[j]<7777) ++i;
				else --j;
			}
			cout<<"No\n";
			return;
		case 2:
			sort(all(v));
			{
			auto it=unique(all(v));
			if(it-v.begin()==n) cout<<"Unique\n";
			else cout<<"Contains duplicate\n";
			}
			return;
		case 3:
			sort(all(v));
			{
			int most=1,most_int=v[0],curr=1;
			forn(i,n-1) {
				if(v[i+1]!=v[i]) curr=0;
				++curr;
				if(curr>most) most_int=v[i+1],most=curr;
			}
			if(2*most>n) cout<<most_int<<'\n';
			else cout<<"-1\n";
			}
			return;
		case 4:
			sort(all(v));
			if((n%2)==0) cout<<v[n/2-1]<<' ';
			cout<<v[n/2];
			cout<<'\n';
			return;
		case 5:
			sort(all(v));
			for(auto i: v) if(100<=i&&i<=999) cout<<i<<' ';
			cout<<'\n';
			return;
	}

}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>t;
	v.resize(n);
	for(auto &i: v) cin>>i;
	solve();
}
