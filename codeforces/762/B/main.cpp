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
 
int a,b,c,m,val;
vi v,u;
string s;

int main() {
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	cin>>a>>b>>c>>m;
	while(m--) {
		cin>>val>>s;
		if(s=="USB") v.push_back(val);
		else u.push_back(val);
	}

	sort(all(v));
	sort(all(u));

	ll ans_num=0,ans_cost=0;
	int v_i=0,u_i=0;
	while(a>0&&v_i<v.size()) ++ans_num,--a,ans_cost+=v[v_i++];
	while(b>0&&u_i<u.size()) ++ans_num,--b,ans_cost+=u[u_i++];
	while(c>0&&(v_i<v.size()||u_i<u.size())) {
		int v_cost=INT_MAX,u_cost=INT_MAX;
		if(v_i<v.size()) v_cost=v[v_i];
		if(u_i<u.size()) u_cost=u[u_i];

		if(v_cost<u_cost) ans_cost+=v_cost,++v_i;
		else ans_cost+=u_cost,++u_i;
		--c;
		++ans_num;
	}

	cout<<ans_num<<' '<<ans_cost<<'\n';

}
