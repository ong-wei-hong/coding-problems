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

int i;
string s;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	while(1) {
		getline(cin,s);
		if(s=="#") break;
		cout<<"Case "<<(++i)<<": ";
		if(s=="HELLO") cout<<"ENGLISH\n";
		else if(s=="HOLA") cout<<"SPANISH\n";
		else if(s=="HALLO") cout<<"GERMAN\n";
		else if(s=="BONJOUR") cout<<"FRENCH\n";
		else if(s=="CIAO") cout<<"ITALIAN\n";
		else if(s=="ZDRAVSTVUJTE") cout<<"RUSSIAN\n";
		else cout<<"UNKNOWN\n";
	}
}
