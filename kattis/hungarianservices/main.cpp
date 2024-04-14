#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<int, vi> hungarian(const vector<vi> &a) {
if (a.empty()) return {0, {}};
int n = sz(a) + 1, m = sz(a[0]) + 1;
vi u(n), v(m), p(m), ans(n - 1);
rep(i,1,n) {
p[0] = i;
int j0 = 0; // add ”dummy” worker 0
vi dist(m, INT_MAX), pre(m, -1);
vector<bool> done(m + 1);
do { // d i jks t ra
done[j0] = true;
int i0 = p[j0], j1, delta = INT_MAX;
rep(j,1,m) if (!done[j]) {
auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
if (dist[j] < delta) delta = dist[j], j1 = j;
}
rep(j,0,m) {
if (done[j]) u[p[j]] += delta, v[j] -= delta;
else dist[j] -= delta;
}
j0 = j1;
} while (p[j0]);
while (j0) { // update a lternating path
int j1 = pre[j0];
p[j0] = p[j1], j0 = j1;
}
}
rep(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;
return {-v[0], ans}; // min cost
}

int n,m,r;
vector<vi> cost;

int main() {
cin.tie(0)->sync_with_stdio(0);
cin.exceptions(cin.failbit);
cin>>n>>m>>r;

cost.resize(n,vi(m,9999));
while(r--) {
	int a,b,c;
	cin>>a>>b>>c;
	--a,--b;
	cost[a][b]=-c;
}

auto [minCost, match] = hungarian(cost);
int ans=0,cst=0;
for(int i=0;i<n;++i) if(cost[i][match[i]]!=9999) ++ans,cst+=-cost[i][match[i]];

cout<<n-ans<<' '<<cst<<'\n';

}
