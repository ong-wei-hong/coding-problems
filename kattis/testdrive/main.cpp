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

int a,b,c,d,e;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>a>>b>>c;
	d=b-a;
	e=c-b;
	if(d==e) cout<<"cruised\n";
	else if(d>0!=e>0) cout<<"turned\n";
	else if(abs(d)>abs(e)) cout<<"braked\n";
	else cout<<"accelerated\n";
}
