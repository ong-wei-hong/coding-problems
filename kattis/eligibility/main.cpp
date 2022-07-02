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

int t,yy1,yy2,c;
string name,s;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--) {
		cin>>name>>yy1>>s>>yy2>>s>>c;
		if(yy1>=2010||yy2>=1991) cout<<name<<" eligible\n";
		else if(c>=41) cout<<name<<" ineligible\n";
		else cout<<name<<" coach petitions\n";
	}
}

