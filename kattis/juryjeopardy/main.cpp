#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()

int t;
string s;
const ii D[4] {{1,0},{0,1},{-1,0},{0,-1}};

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	cout<<t<<'\n';
	while(t--) {
		set<ii> se;
		int max_x{0},min_y{0},max_y{0},d{0};
		ii curr{0,0};
		se.insert(curr);
		cin>>s;
		for(const auto& c: s) {
			switch(c) {
				case 'R':
					d=(d+1)%4;
					break;
				case 'L':
					d=(d+3)%4;
					break;
				case 'B':
					d=(d+2)%4;
					break;
			}
			curr.first+=D[d].first;
			curr.second+=D[d].second;
			se.insert(curr);
			max_x=max(max_x,curr.first);
			min_y=min(min_y,curr.second);
			max_y=max(max_y,curr.second);
		}
		cout<<max_y-min_y+3<<' '<<max_x+2<<'\n';
		for(int j{min_y-1};j<=max_y+1;++j) {
			forn(i,max_x+2) {
				ii temp {i,j};
				if(se.find(temp)==se.end()) cout<<'#';
				else cout<<'.';
			}
			cout<<'\n';
		}
	}
				


					

		
}
