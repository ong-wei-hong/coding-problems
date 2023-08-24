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
string line,word;
char vowels[6] {'a','e','i','o','u','y'};

void solve() {
	if(find(vowels,vowels+6,word[0])!=vowels+6) {
		cout<<word<<"yay";
		return;
	}
	int mini=word.size();
	forn(i,6) {
		int j=word.find(vowels[i]);
		mini=min(mini,j==-1?(int)word.size():j);
	}
	for(int i=mini;i<word.size();++i) cout<<word[i];
	forn(i,mini) cout<<word[i];
	cout<<"ay";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(getline(cin,line)) {
		int start=0;
		bool first=1;
		for(int i=line.find(" ",0);i!=-1;i=line.find(" ",start)) {
			if(first) first=0;
			else cout<<' ';
			word=line.substr(start,i-start);
			solve();
			start=i+1;
		}
		cout<<' ';
		word=line.substr(start);
		solve();
		cout<<'\n';
	}
}
			
