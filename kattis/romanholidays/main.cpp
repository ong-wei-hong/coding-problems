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
vector<string> v,u;

int findIndex(vector<string> &v, string &s) {
	forn(i,v.size()) if(v[i]==s) return i;
	return -1;
}

string toRoman(int i) {
	int l[13] {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string m[13] {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"}, ans="";
	int j=12;
	while(i) {
		while(i>=l[j]) ans+=m[j],i-=l[j];
		--j;
	}
	return ans;
}

void solve() {
	cin>>n;
	int a=n/1000;
	n%=1000;
	string b=toRoman(n);
	if(b[0]=='X'||b[0]=='V') cout<<findIndex(v, b)-(a+1)*(int)v.size()<<'\n';
	else cout<<a*u.size()+findIndex(u,b)+1<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	for(int i=1;i<=1000;++i) {
		string s=toRoman(i);
		if(s[0]=='X'||s[0]=='V') v.pb(s);
		else u.pb(s);
	}
	sort(all(v));
	sort(all(u));
	
	cin>>t;
	while(t--) solve();
}
