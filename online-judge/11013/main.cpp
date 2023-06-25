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

int t,freq[14],cards[5];
string line;
char suite[5];

void solve() {
}

double calc_winnings() {
	int count[13],scores[6];
	memset(count,0,sizeof(count));
	memset(scores,0,sizeof(scores));
	for(int i: cards) ++count[i-1];

	for(int i=0;i<13;++i) {
		int longest=0;
		for(int j=i;count[j%13];++j,++longest);
		if(longest>2) ++scores[longest];
		scores[2]+=min(count[i],count[(i+1)%13]);
	}

	if(scores[5]) return 100.0;
	else if(scores[4]) return 10.0;
	else if(scores[3]&&scores[2]>2) return 5.0;
	else if(scores[3]) return 3.0;
	else if(scores[2]>1) return 1.0;
	return 0.0;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(getline(cin,line)) {
		if(line=="#") break;
		
		for(auto &i: freq) i=4;

		forn(i,5) {
			suite[i]=line[3*i+1];
			int c;
			switch(line[3*i]) {
				case 'A': c=1; break;
				case 'T': c=10; break;
				case 'J': c=11; break;
				case 'Q': c=12; break;
				case 'K': c=13; break;
				default: c=line[3*i]-'0';
			}
			cards[i]=c;
			--freq[c];
		}

		double winnings=calc_winnings();
		int toTrade=-1;
		//cout<<winnings<<'\n';
		forn(i,5) {
			double expected=-1;
			int ori=cards[i];
			forn(j,13) cards[i]=j+1,expected+=(1.0*freq[j+1]/47.0*calc_winnings());
			if(expected>winnings) winnings=expected,toTrade=i;
			cards[i]=ori;
			//cout<<i<<' '<<expected<<'\n';
		}
		
		if(toTrade==-1) cout<<"Stay\n";
		else {
			cout<<"Exchange ";
			switch(cards[toTrade]) {
				case 1: cout<<'A'; break;
				case 10: cout<<'T'; break;
				case 11: cout<<'J'; break;
				case 12: cout<<'Q'; break;
				case 13: cout<<'K'; break;
				default: cout<<cards[toTrade];
			}
			cout<<suite[toTrade]<<'\n';
		}
	}
}
