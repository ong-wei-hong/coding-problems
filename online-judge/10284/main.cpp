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
char s[99],board[64];

void solve() {
}

int get_pos(int r, int c) {
	return r*8+c;
}

void print_board() {
	forn(i,8){
		forn(j,8) printf("%c",board[get_pos(i,j)]);
		printf("\n");
	}
}


bool attack(int r, int c) {
	if(r>=0&&r<8&&c>=0&&c<8&&(board[get_pos(r,c)]==' '||board[get_pos(r,c)]=='0')) {
		board[get_pos(r,c)]='0';
		return 1;
	}
	return 0;
}

void cont_attack(int r, int c, int* drs, int* dcs, int l) {
	forn(i,l) {
		int dr=drs[i],dc=dcs[i];
		for(int a=r+dr,b=c+dc;attack(a,b);a+=dr,b+=dc);
	}
}

void single_attack(int r, int c, int* drs, int* dcs, int l) {
	forn(i,l) {
		int dr=drs[i],dc=dcs[i];
		attack(r+dr,c+dc);
	}
}

void rook(int r, int c) {
	int drs[4]{-1,1,0,0},dcs[4]{0,0,-1,1};
	cont_attack(r,c,drs,dcs,4);
}


void knight(int r, int c) {
	int drs[8]={-2,-2,-1,-1,1,1,2,2},dcs[8]={-1,1,-2,2,-2,2,-1,1};
	single_attack(r,c,drs,dcs,8);
}

void bishop(int r, int c) {
	int drs[4]{-1,-1,1,1},dcs[4]{-1,1,-1,1};
	cont_attack(r,c,drs,dcs,4);
}

void queen(int r, int c) {
	rook(r,c);bishop(r,c);
}

void king(int r, int c) {
	int drs[8]={-1,-1,-1,0,0,1,1,1},dcs[8]={-1,0,1,-1,1,-1,0,1};
	single_attack(r,c,drs,dcs,8);
}

void pawn(int r,int c,int dr) {
	attack(r+dr,c+1);
	attack(r+dr,c-1);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(scanf("%s\n",&s)!=EOF) {
		memset(board,' ',sizeof(board));
		int i=0,j=0;
		for(auto c: s) {
			if(c=='\0') break;
			if(c=='/') ++i,j=0;
			else if('1'<=c&&c<='8') j+=c-'0';
			else board[get_pos(i,j)]=c,++j;
		}
		forn(i,8) forn(j,8) switch(board[get_pos(i,j)]) {
			case 'r': case 'R':
				rook(i,j); break;
			case 'n': case 'N':
				knight(i,j); break;
			case 'b': case 'B':
				bishop(i,j); break;
			case 'q': case 'Q':
				queen(i,j); break;
			case 'k': case 'K':
				king(i,j); break;
			case 'p': pawn(i,j,1); break;
			case 'P': pawn(i,j,-1); break;
		}
		int ans=0;
		for(auto c: board) ans+=(c==' ');
		//printf("\n");
		//print_board();
		printf("%d\n",ans);
	}
}
