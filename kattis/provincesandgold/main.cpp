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

int g,s,c;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>g>>s>>c;
	int b=3*g+2*s+c;
	if(b>=2) {
		if(b>=8) cout<<"Province or ";
		else if(b>=5) cout<<"Duchy or ";
		else cout<<"Estate or ";
	}
	if(b>=6) cout<<"Gold\n";
	else if(b>=3) cout<<"Silver\n";
	else cout<<"Copper\n";
}
