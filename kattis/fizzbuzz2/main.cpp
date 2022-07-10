#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

#define fi first
#define se second
#define pb push_back

int n,m,a,b;
string s;

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>n>>m;
	forn(i,n) {
		int r=0;
		for(int j=1;j<=m;++j) {
			cin>>s;
			if(j%3==0&&j%5==0) r+=s=="fizzbuzz";
			else if(j%3==0) r+=s=="fizz";
			else if(j%5==0) r+=s=="buzz";
			else r+=s==to_string(j);
		}
		if(r>b) a=i,b=r;
	}
	cout<<a+1<<'\n';
}
