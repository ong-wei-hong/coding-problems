#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int n,i;
string s;
void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	//cin>>t;
	//while(t--) solve();
	cin>>n;
	getline(cin,s);
	int i=1;
	for(const auto& c: s)
		switch(c) {
			case 'L': i*=2;break;
			case 'R': i=i*2+1; break;
		}
	cout<<((int)(pow(2,n+1)-i))<<'\n';
}
