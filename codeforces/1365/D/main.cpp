#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define LSB(x) (x) & (-x)
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n,m,cntGood,cntBad;
vector<string> maze;
vector<vector<bool>> vis;

void dfs(int i, int j) {
	if (i<0||i>=n||j<0||j>=m||vis[i][j]||maze[i][j] == '#') return;
	vis[i][j] = 1;
	cntGood += maze[i][j] == 'G';
	cntBad += maze[i][j] == 'B';

	int di[4] {-1,1,0,0},dj[4]{0,0,-1,1};
	rep(k,0,4) {
		int new_i = i + di[k], new_j = j + dj[k];
		dfs(new_i, new_j);
	}
}

void solve() {
	cin>>n>>m;
	maze.resize(n);
	vis.assign(n,vector<bool>(m,0));
	for(auto &s: maze) cin>>s;
	cntGood=cntBad=0;

	int numGood = 0;
	rep(i,0,n) rep(j,0,m) {
		if(maze[i][j] == 'B') {
			int di[4] {-1,1,0,0},dj[4] {0,0,-1,1};
			rep(k,0,4) {
				int new_i = i + di[k], new_j = j + dj[k];
				if(0<=new_i && new_i < n && 0 <= new_j && new_j < m && maze[new_i][new_j] == '.')
					maze[new_i][new_j] = '#';
			}
		}

		numGood += maze[i][j] == 'G';
	}

	dfs(n-1,m-1);

//	cout<<'\n';
//	for(auto &s: maze) cout<<s<<'\n';
//	cout<<'\n';

	if (cntGood == numGood && cntBad == 0) cout<<"Yes\n";
	else cout<<"No\n";
}

int main() {
//	freopen("perimeter.in", "r", stdin);
//	freopen("perimeter.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
