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

int t;
string qwerty[2][4] {{"`1234567890-="," qwertyuiop[]\\"," asdfghjkl;'"," zxcvbnm,./"},{"~!@#$%^&*()_+"," QWERTYUIOP{}|"," ASDFGHJKL:\""," ZXCVBNM<>?"}},
       dvorak[2][4] {{"`123qjlmfp/[]"," 456.orsuyb;=\\"," 789aehtdck-"," 0zx,inwvg'"},{"~!@#QJLMFP?{}"," $%^>ORSUYB:+|"," &*(AEHTDCK_"," )ZX<INWVG\""}},
       s,
       hands[3] {"asdfjkl;","fghj","ehtd"};

ii lookfor(string keyboard[2][4], char c) {
	forn(a,2) forn(i,4) for(int j=0;j<keyboard[a][i].size();++j) if(c==keyboard[a][i][j]) return mp(i,j);
	return mp(-1,-1);
}

double calc(string keyboard[2][4], char hand, char look){
	ii f=lookfor(keyboard,hand),s=lookfor(keyboard,look);
	if(s.fi==-1) return 0;
	return sqrt(pow(f.fi-s.fi,2)+pow(f.se-s.se,2))*2;
}

double solve(string keyboard[2][4], string& hand) {
	double ans=0;
	for(char c: s) {
		if(c==' ') continue;
		double curr=1000000;
		for(char d: hand) curr=min(curr,calc(keyboard,d,c));
		ans+=curr;
	}
	return ans;
}

void solve() {
	cout<<fixed<<setprecision(2)<<solve(qwerty,hands[0])<<' '<<solve(qwerty,hands[1])<<' '<<solve(dvorak,hands[2])<<'\n';
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(getline(cin,s)) {
		solve();
	}
}
