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
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll m,n,a;


ll euclid(ll a, ll b, ll &x, ll &y) {
if (!b) return x = 1, y = 0, a;
ll d = euclid(b, a % b, y, x);
return y -= a/b * x, d;
}

const ll mod = 1e9 + 7; // change to something e lse
struct Mod {
ll x;
Mod(ll xx) : x(xx) {}
Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
Mod operator/(Mod b) { return *this * invert(b); }
Mod invert(Mod a) {
ll x, y, g = euclid(a.x, mod, x, y);
assert(g == 1); return Mod((x + mod) % mod);
}
Mod operator^(ll e) {
if (!e) return Mod(1);
Mod r = *this ^ (e / 2); r = r * r;
return e&1 ? *this * r : r;
}
};

void solve() {
	cin>>n>>m;
	map<int,int> cumExist;
	map<int,Mod> level_to_cum_cnt;

	rep(i,0,n) {
		cin>>a;
		auto it = level_to_cum_cnt.find(a);
		if (it == level_to_cum_cnt.end()) {
			level_to_cum_cnt.insert({a, 1});
		} else {
			it->se = it->se + 1;
		}
	}

	{
		ll cumExistCnt = 0;
		Mod cum_cnt = 1;
		for(auto &p : level_to_cum_cnt) {
			cumExist[p.fi] = ++cumExistCnt;
			cum_cnt = p.se * cum_cnt;
			p.se = cum_cnt;
		}
	}

//	cout<<"level_to_cum_cnt\n";
//	for(auto &p : level_to_cum_cnt) {
//		cout<<p.fi<<':'<<p.se.x<<'\n';
//	}
//	cout<<"cumExist\n";
//	for(auto &p : cumExist) {
//		cout<<p.fi<<':'<<p.se<<'\n';
//	}
	
	Mod ans = 0;
	for(const auto &p : cumExist) {
		auto it = cumExist.find(p.fi + m - 1);

		if (it == cumExist.end() || it->se != p.se + m - 1) {
			continue;
		}


		Mod lb = 1;
		auto it2 = level_to_cum_cnt.upper_bound(p.fi - 1);
		if (it2 != level_to_cum_cnt.begin()) {
			lb = (--it2)->se;
		}
		ans = ans + level_to_cum_cnt.at(p.fi + m - 1) / lb;
	}

	cout<<ans.x<<'\n';

}

int main() {
//	freopen("pails.in", "r", stdin);
//	freopen("pails.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
