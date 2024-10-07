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

int N,Q,NO,COL;
vi A,C;
map<int,vector<ll>> color_to_A;
map<int,ll> offset;
ll add,X;

void solve() {
	cin>>N;
	A.resize(N);
	C.resize(N);
	for(auto &i: A) cin>>i;
	for(auto &i: C) cin>>i;

	rep(i,0,N) color_to_A[C[i]].push_back(A[i]);
	for(auto &it: color_to_A) {
		auto &v = it.se;
		rep(i,1,v.size()) v[i] += v[i-1];
	}

	cin>>Q;
	while(Q--) {
		cin>>NO>>COL>>X;
		if(NO==1) add += X, offset[COL]+=X;
		if(NO==2) {
			auto &v = color_to_A[COL];
			int lb=0,ub=v.size();
			while(lb<ub) {
				int mid=(lb+ub+1)/2;
				ll curr_sum = color_to_A[COL][mid-1] + mid * (add - offset[COL]);
				if (curr_sum <= X) lb = mid;
				else ub=mid-1;
			}

			cout<<lb<<'\n';
		}
	}
}

int main() {
//	freopen("loan.in", "r", stdin);
//	freopen("loan.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	solve();
}
