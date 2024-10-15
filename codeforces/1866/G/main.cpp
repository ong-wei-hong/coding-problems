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

int N;
vi A,D;
vector<tuple<int,int,int>> line_segments;

bool valid(ll max_ppl_per_car) {
	int line_segments_i=0;
	std::priority_queue<pii> pq;


	rep(car,0,N) {
		ll car_space = max_ppl_per_car;
		while(line_segments_i < N) {
			auto &[left, right, amt] = line_segments[line_segments_i];
			if (left > car) break;
			pq.push({-right, amt});

			line_segments_i++;
		}

		while (car_space > 0 && !pq.empty()) {
			auto [neg_right, amt] = pq.top(); pq.pop();

			int right=-neg_right, new_amt=amt;

			if (right<car) {
				pq.push({neg_right, amt});
				break;
			}
			ll delta = min(1LL*new_amt, car_space);
			new_amt -= delta;
			car_space -= delta;

			if (new_amt != 0) {
				assert( car_space == 0);
				pq.push({neg_right, new_amt});
			}
		}
	}


	while (!pq.empty()) {
		auto &[_, amt] = pq.top(); pq.pop();
		if (amt > 0) return false;
	}

	return true;
}

void solve() {
	cin>>N;
	A.resize(N);
	D.resize(N);
	for(auto &i: A) cin>>i;
	for(auto &i: D) cin>>i;
	
	line_segments.resize(N);
	rep(i,0,N) line_segments[i] = {i-D[i], i+D[i], A[i]};
	sort(all(line_segments));

	ll lb=1,ub=2e14;
	while(lb<ub) {
		ll mid=(lb+ub)/2;
		if (valid(mid)) ub=mid;
		else lb=mid+1;
	}

	cout<<ub<<'\n';
}

int main() {
//	freopen("loan.in", "r", stdin);
//	freopen("loan.out", "w", stdout);
//	cin.tie(0)->sync_with_stdio(0);
//	cin.exceptions(cin.failbit);

	solve();
}
