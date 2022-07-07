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

string s,t,u;
int a,b,c;

void solve() {
}

int d(const string& s) {
	if(s=="North") return 0;
	if(s=="East") return 1;
	if(s=="South") return 2;
	if(s=="West") return 3;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>s>>t>>u;
	a=d(s),b=d(t),c=d(u);
	if(((a+2)%4==b&&(a+3)%4==c)||((a+1)%4==b&&((a+3)%4==c||(a+2)%4==c))) cout<<"Yes\n";
	else cout<<"No\n";
}
