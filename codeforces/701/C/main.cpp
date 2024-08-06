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

int n,a[255],b[255],total;
string s;

int main() {
	//freopen("meetings.in", "r", stdin);
	//freopen("meetings.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin>>n>>s;
	for(auto c: s) total+=((++a[c])==1);
	int curr=0,i=0,ans=INT_MAX;
	rep(j,0,n) {
		curr+=((++b[s[j]])==1);
		if(curr==total) {
			while(curr==total) {
				curr-=(--b[s[i]])==0;
				++i;
			}
			ans=min(ans,j-i+2);
		}
	}

	cout<<ans<<'\n';
}

