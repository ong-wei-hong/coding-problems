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

int n;
int prevCnt[10];
vi items,idxToRmv;

void point(int idx) {
	cout<<"! "<<idx<<'\n';
	cout.flush();
}

void removeItems() {
	cout<<"- "<<idxToRmv.size();
	for(auto idx: idxToRmv) {
		cout<<' '<<idx;
	}
	cout<<'\n';
	cout.flush();
}

void solve() {
	int currCnt[10];

	cin >> n;
	memset(prevCnt, 0, sizeof prevCnt);
	memset(currCnt, 0, sizeof currCnt);
	items.resize(n);
	for(auto &item: items) {
		cin>>item;
		++prevCnt[item];
		++currCnt[item];
	}

	while(1) {
		if(n == 1) {
			point(1);
			return;
		}
		
		bool itemsRemoved = false;
		rep(i,1,10) {
			if(currCnt[i] == prevCnt[i] + 1) {
				if (currCnt[i] == 1) {
					rep(j,0,n) if(items[j] == i) {
						point(j+1);
						return;
					}
				}

				idxToRmv.clear();
				rep(j,0,n) if(items[j] != i) {
					idxToRmv.push_back(j+1);
				}
				n -= idxToRmv.size();
				memset(prevCnt, 0, sizeof prevCnt);
				prevCnt[i] = n;
				removeItems();
				itemsRemoved = true;
				break;
			}
			prevCnt[i] = currCnt[i];
		}

		if (!itemsRemoved) {
			idxToRmv.clear();
			removeItems();
		}

		memset(currCnt, 0, sizeof currCnt);
		items.resize(n);
		for(auto &item: items) {
			cin>>item;
			++currCnt[item];
		}
	}
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
