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

int ufds_find_set(vi& ufds, int i){
	if(ufds[i]==i) return i;
	return ufds[i]=ufds_find_set(ufds,ufds[i]);
}

void ufds_union_set(vi& ufds, vi& rank, int i, int j){
	i = ufds_find_set(ufds,i);
	j = ufds_find_set(ufds,j);
	if(i==j) return;
	if(rank[i]>rank[j]) ufds[j]=i;
	else ufds[i]=j,++rank[j];
}

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
		if(y&1) z*=x;
		x=mul(x,x);
		y>>=1;
	}
	return z;
}

bool prime(ll x) {
	for(ll i=2;i*i<=x;++i)
		if(x%i==0) return false;
	return true;
}

int a,b,c,d;

int solve() {
	if((a==2&&b==1)||(c==2&&d==1)) return (a==2&&b==1)+2*(c==2&&d==1);
	if(a==b||c==d) {
		if(c!=d) return 1;
		if(a!=b) return 2;
	}
	int fi=a*10+b,se=c*10+d;
	return (fi>=se)+2*(se>=fi);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(true) {
		cin>>a>>b>>c>>d;
		if((a||b||c||d)==0) break;
		if(a<b)swap(a,b);
		if(c<d)swap(c,d);
		switch(solve()) {
			case 1: cout<<"Player 1 wins.\n"; break;
			case 2: cout<<"Player 2 wins.\n"; break;
			case 3: cout<<"Tie.\n"; break;
		}
	}
}
