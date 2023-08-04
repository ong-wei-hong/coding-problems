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

int t,mins;
unordered_map<string,int> m {
	{"UTC", 0},
		{"GMT", 0},
		{"BST", 2},
		{"IST", 2},
		{"WET", 0},
		{"WEST", 2},
		{"CET", 2},
		{"CEST", 4},
		{"EET", 4},
		{"EEST", 6},
		{"MSK", 6},
		{"MSD", 8},
		{"AST", -8},
		{"ADT", -6},
		{"NST", -7},
		{"NDT", -5},
		{"EST", -10},
		{"EDT", -8},
		{"CST", -12},
		{"CDT", -10},
		{"MST", -14},
		{"MDT", -12},
		{"PST", -16},
		{"PDT", -14},
		{"HST", -20},
		{"AKST", -18},
		{"AKDT", -16},
		{"AEST", 20},
		{"AEDT", 22},
		{"ACST", 19},
		{"ACDT", 21},
		{"AWST", 16},
};
string s,t1,t2;

void solve() {
	cin>>s;
	if(s=="noon") mins=12*60;
	else if(s=="midnight") mins=0;
	else {
		int hh=stoi(s.substr(0,s.size()-3)),mm=stoi(s.substr(s.size()-2,2));
		cin>>s;
		mins=(hh%12)*60+mm;
		if(s=="p.m.") mins+=12*60;
	}
	cin>>t1>>t2;
	int diff=m[t2]-m[t1];
	mins+=(diff*30);
	mins=(mins+24*60)%(24*60);
	if(mins==0) cout<<"midnight\n";
	else if(mins==12*60) cout<<"noon\n";
	else {
		int hh=mins/60,mm=mins%60;
		bool am=1;
		if(hh==0) hh+=12,am=1;
		else if(hh<12) am=1;
		else if(hh==12) am=0;
		else hh-=12,am=0;

		cout<<hh<<':';
		if(mm<10) cout<<'0';
		cout<<mm<<' ';
		if(am) cout<<"a.m.";
		else cout<<"p.m.";
		cout<<'\n';
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve();
}
