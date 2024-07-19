#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define LSB(x) (x) & (-x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <class T>
using Tree =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct RollbackUF {
vi e;
vector<pii> st;
RollbackUF(int n) : e(n, -1) {}
int size(int x) { return -e[find(x)]; }
int find(int x) { return e[x] < 0 ? x : find(e[x]); }
int time() { return sz(st); }
void rollback(int t) {
	for (int i = time(); i-- > t;)
		e[st[i].first] = st[i].second;
	st.resize(t);
}
bool join(int a, int b) {
	a = find(a), b = find(b);
	if (a == b)
		return false;
	if (e[a] > e[b])
		swap(a, b);
	st.push_back({a, e[a]});
	st.push_back({b, e[b]});
	e[a] += e[b];
	e[b] = a;
	return true;
}
};

int n;
vector<int> m;
vector<pii> a,ops;


void solve() {
	cin>>n;
	a.resize(n);
	rep(i,0,n) cin>>a[i].first,a[i].second=i+1;

	ops.resize(n-1);
	for(int i=n-2;i>=0;--i) {
		m.assign(i+1,-1);
		rep(j,0,a.size()) {
			int idx=(a[j].first)%(i+1);
			if(m[idx]!=-1) {
				ops[i]={a[j].second,m[idx]};
				a.erase(a.begin()+j);
				break;
			}
			m[idx]=a[j].second;
		}
	}

	cout<<"YES\n";
	for(auto &it: ops) cout<<it.first<<' '<<it.second<<'\n';
}

int main() {
	// freopen("lazy.in", "r", stdin);
	// freopen("lazy.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}

