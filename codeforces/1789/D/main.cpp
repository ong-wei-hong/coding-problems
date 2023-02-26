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
string a,b;
vi ans;

void xor_string(int shift) {
	ans.pb(shift);
	string c=a;
	//cout<<shift<<' ';
	if(shift>0) for(int i=n-1;i-shift>=0;--i) a[i-shift]=(c[i]==a[i-shift] ? '0' : '1');
	else {
		shift=-shift;
		forn(i,n-shift) a[i+shift]=(c[i]==a[i+shift] ? '0' : '1');
	}
	//cout<<a<<'\n';
}

void solve() {
	cin>>n>>a>>b;
	if(a==b){
		cout<<"0\n";
		return;
	}
	int al=a.rfind('1'), bf=b.find('1');
	if(al==-1||bf==-1) {
		cout<<"-1\n";
		return;
	}
	ans.clear();
	
	if(al<bf) xor_string(al-bf), al=bf;
	for(int i=bf-1;i>=0;--i) if(a[i]=='1') xor_string(al-i);
	if(a[bf]!='1') xor_string(a.find('1')-bf);
	for(int i=bf+1;i<n;++i) if(a[i]!=b[i]) xor_string(bf-i);

	cout<<ans.size()<<'\n';
	for(auto i: ans) cout<<i<<' ';
	cout<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
