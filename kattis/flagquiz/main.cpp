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

string s;
int n;
vector<string> input;
vector<vector<string>> v;
vi points;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	getline(cin,s);
	cin>>n;
	cin.ignore(10,'\n');
	forn(i,n) {
		getline(cin,s);
		input.push_back(s);
		v.emplace_back();
		int start=0,e=s.find(", ");
		while(e!=-1) {
			v.back().push_back(s.substr(start,e-start));
			start=e+2;
			e=s.find(", ",start);
		}
		v.back().push_back(s.substr(start));
		points.push_back(0);
	}

	forn(i,n) 
		for(int j=i+1;j<n;++j) {
			int p=0;
			forn(k,v[j].size()) p+=(v[i][k]!=v[j][k]);
			points[i]=max(points[i],p);
			points[j]=max(points[j],p);
		}

	int min_points = *min_element(points.begin(),points.end());
	unordered_set<string> s;
	forn(i,n)
		if(points[i]==min_points&&s.find(input[i])==s.end()) cout<<input[i]<<'\n',s.insert(input[i]);

}
