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

int t,a;
vi arr,ans,cnt;
pq<int,vector<int>,greater<int>> q;
vector<set<int>> al;

void print() {
	cout<<"\nans\n";
	for(auto i: ans) cout<<i<<' ';
	cout<<'\n';

	cout<<"\nal\n";
	for(auto &i: al) {
		for(auto j: i) cout<<j<<' ';
		cout<<'\n';
	}
	cout<<'\n';
}


bool solve() {
	forn(i,t+1) if(!cnt[i]) q.push(i);
	forn(i,t) {
		if(q.empty()) return false;
		ans.pb(q.top());
		al[q.top()].insert(arr[i]);
		al[arr[i]].insert(q.top());
		q.pop();
		--cnt[arr[i]];
		if(cnt[arr[i]]==0) q.push(arr[i]);
	}
	
	q.pop();
	forn(i,t+1) if(al[i].size()==1) q.push(i);
	//print();
	forn(i,t) {
		if(q.empty()) return false;
		int j=q.top();
		q.pop();
		if(ans[i]!=j) return false;
		al[*al[j].begin()].erase(j);
		if(al[*al[j].begin()].size()==1) q.push(*al[j].begin());
		
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	cnt.resize(t+1);
	arr.resize(t);
	al.resize(t+1);
	for(auto &i: arr) cin>>i,--i,++cnt[i];
	if(solve()) for(auto i: ans) cout<<++i<<'\n';
	else cout<<"Error\n";
}
