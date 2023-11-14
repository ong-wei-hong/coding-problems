#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int, int>>
#define pq std::priority_queue

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair

template<typename T>
using ost = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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

int c;
string s,t;
set<string> sets[3];
ost<string> osts[3];

int count(int i) {
	if(i==0) return count(1)+count(2);
	auto it=sets[i].lower_bound(s),it2=sets[i].lower_bound(t);
	if(it2==sets[i].begin()||it==sets[i].end()) return 0;
	--it2;
	//cout<<"after "<<s<<':'<<*it<<'\n';
	//cout<<"before "<<t<<':'<<*it2<<'\n';
	return osts[i].order_of_key(*it2) - osts[i].order_of_key(*it) +1;
}

void solve() {
	while(cin>>c) {
		if(!c) break;

		if(c==1) {
			cin>>s>>c;
			sets[c].insert(s);
			osts[c].insert(s);
		} else if(c==2) {
			cin>>s;
			forn(i,3) 
				if(sets[i].count(s)) {
					sets[i].erase(s);
					osts[i].erase(s);
				}
		} else if(c==3) {
			cin>>s>>t>>c;
			cout<<count(c)<<'\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}
