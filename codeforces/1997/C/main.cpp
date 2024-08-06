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

int n;
string s;

void solve() {
	cin>>n>>s;

	{
		int i=0;
		for(auto &c: s) {
			if(c=='_') {
				if(i>0) c=')';
				else c='(';
			}

			i+=(c=='(');
			i-=(c==')');
		}
	}

	stack<int> st;
	int ans=0;
	rep(i,0,n) {
		if(s[i]==')') {
			auto j=st.top();st.pop();
			ans+=(i-j);
		}
		if(s[i]=='(') st.push(i);
	}

	cout<<ans<<'\n';
}

int main() {
	//freopen("triangles.in", "r", stdin);
	//freopen("triangles.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin>>t;
	while(t--) solve();
}
