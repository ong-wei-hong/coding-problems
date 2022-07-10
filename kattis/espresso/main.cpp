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

int n,s,a,r,x;
string t;

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>n>>s;
	cin.ignore(256,'\n');
	r=s;
	while(n--) {
		getline(cin,t);
		if(t[t.length()-1]=='L'){
			a=stoi(t.substr(0,t.length()-1))+1;
		}
		else a=stoi(t);
		if(a>r) ++x,r=s-a;
		else r-=a;
	}
	cout<<x<<'\n';
}
