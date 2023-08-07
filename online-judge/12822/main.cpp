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

int t,p[10]{6,2,5,5,4,5,6,3,7,6};
string a,b,c,d,currTime;

int count(int score) {
	if(score==0) return p[0];
	int ans=0;
	while(score) ans+=p[score%10],score/=10;
	return ans;
}


int consume(int home, int guest) {
	int diff,hh=stoi(b.substr(0,2))-stoi(currTime.substr(0,2)),mm=stoi(b.substr(3,2))-stoi(currTime.substr(3,2)),dd=stoi(b.substr(6,2))-stoi(currTime.substr(6,2));
	diff=3600*hh+60*mm+dd;
	return diff*count(home)+diff*count(guest);
}


void solve() {
	currTime=b;
	int ans=0,home=0,guest=0;
	while(1) {
		cin>>a>>b;
		ans+=consume(home,guest);
		if(a=="END") break;
		cin>>c>>d;
		if(c=="home") home+=stoi(d);
		else guest+=stoi(d);
		currTime=b;
	}
	cout<<ans<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t=0;
	while(cin>>a>>b) {
		cout<<"Case "<<++t<<": ";
		solve();
	}
}
