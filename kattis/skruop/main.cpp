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

int n,a{7};
string s;

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>n;
	cin.ignore(256,'\n');
	while(n--) {
		getline(cin,s);
		switch(s[5]) {
			case 'o': a=min(10,a+1); break;
			case 'n': a=max(0,a-1); break;
		}
	}
	cout<<a<<'\n';
}
