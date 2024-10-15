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

int n;
string s;
vi pellets,pacmans;

bool valid(int max_time) {
	auto it=pellets.begin();

//	cout<<"time: "<<max_time<<"\n";

	for(auto pacman: pacmans) {
		if (it == pellets.end()) return 1;
		if (*it < pacman && pacman - (*it) > max_time) return 0;
		if (*it > pacman) {
			int right = pacman + max_time;
			
//			cout<<"pacman: "<<pacman<<": "<<pacman<<','<<right<<'\n';
			

			while(it != pellets.end() && (*it) <= right) ++it;
			continue;
		}

		int left = *it,right;
		right = pacman + max(max_time - 2 * (pacman - left), (max_time - (pacman - left)) / 2);
//		cout<<"pacman: "<<pacman<<": "<<left<<','<<right<<'\n';

		while (it != pellets.end() && (*it) <= right) ++it;
	}

	return it == pellets.end() ? 1 : 0;
}

void solve() {
	cin>>n>>s;
	int lb=0,ub=2e5;
	
	rep(i,0,n)
		if (s[i] == '*') pellets.push_back(i);
		else if (s[i] == 'P') pacmans.push_back(i);

	while(lb<ub) {
		int mid=(lb+ub)/2;
		if(valid(mid)) ub=mid;
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
