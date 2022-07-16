#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair

int t;
string s;
const vii m{{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>s;
		ii st=mp(s[0]-'a',s[1]-'1');
		vector<vi> b(8,vi(8,-1));
		b[st.fi][st.se]=0;
		queue<ii> q;
		q.push(st);
		int ma=0;
		while(!q.empty()) {
			ii c=q.front();
			q.pop();
			for(auto& i: m) {
				int x=c.fi+i.fi,y=c.se+i.se;
				if(x>=0&&x<8&&y>=0&&y<8&&b[x][y]==-1) b[x][y]=b[c.fi][c.se]+1,q.emplace(x,y),ma=max(ma,b[c.fi][c.se]+1);
			}
		}
		cout<<ma<<' ';
		for(int i=7;i>=0;--i) for(int j=0;j<8;++j) if(b[j][i]==ma) cout<<' '<<(char)(j+'a')<<i+1;
		cout<<'\n';
	}
}
