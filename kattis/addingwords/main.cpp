#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;

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

string s,line;
char c;
unordered_map<string,int> m;
unordered_map<int,string> m2;
int i;

void solve() {
	while(cin>>s) {
		if(s=="def") {
			cin>>s>>i;
			auto it=m.find(s);
			if(it!=m.end()) m2.erase(it->se),it->se=i;
			else m[s]=i;
			m2[i]=s;
		} else if(s=="clear") {
			m.clear();
			m2.clear();
		} else {
			line="";
			bool b=0;
			i=0;
			for(c='+';c!='=';cin>>c) {
				cin>>s;
				auto it=m.find(s);
				if(it==m.end()) b=1;
				else if(c=='+') i+=it->se;
				else i-=it->se;

				line += c;
				line += ' ';
				line += s;
				line += ' ';
			}

			cout<<line.substr(2)<<"= ";

			auto it = m2.find(i);
			if(b||it==m2.end()) cout<<"unknown\n";
			else cout<<it->se<<'\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}
