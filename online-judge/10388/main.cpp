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
string s1, s2;

void f(deque<char>& down, deque<char>& up) {
	while(!up.empty()) {
		down.pb(up.back());
		up.pop_back();
	}
}

void g(deque<char>& down, deque<char>& up) {
	up.push_front(down.front());
	down.pop_front();
}

void h(deque<char>& to, deque<char>& from, string name) {
	cout<<"Snap! for "<<name<<": ";
	while(!from.empty()) {
		to.push_front(from.back());
		from.pop_back();
	}
	for(auto it=to.begin();it!=to.end();++it) cout<<*it;
	cout<<'\n';
}

bool a(deque<char> d, string name) {
	if(d.empty()) {
		cout<<name<<" wins.\n";
		return true;
	}
	return false;
}

void solve() {
	cin>>s1>>s2;
	deque<char> john_up, john_down, jane_up, jane_down;
	for(auto c: s1) jane_down.pb(c);
	for(auto c: s2) john_down.pb(c);

	forn(i,1000) {
		if(jane_down.empty()) 
			f(jane_down, jane_up);
		if(john_down.empty())
			f(john_down, john_up);
		
		g(jane_down, jane_up);
		g(john_down, john_up);

		if(jane_up.front()==john_up.front()) 
			if(random()/141%2) {
				h(john_up, jane_up, "John");
				if(a(jane_down, "John")) return;
			} else {
				h(jane_up, john_up, "Jane");
				if(a(john_down, "Jane")) return;
			}
	}
	cout<<"Keeps going and going ...\n";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) solve(),cout<<"\n"[t==0];
	//forn(i,t) cout<<"Case "<<i+1<<": ", solve();
}
