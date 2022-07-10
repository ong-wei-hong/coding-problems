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

string s;

void solve();

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>s;
	forn(i,s.length()) 
		switch(s[i]) {
			case ':':
			case ';':
				if(i+1<s.length()&&s[i+1]==')') cout<<i<<'\n',++i;
				else if(i+2<s.length()&&s[i+1]=='-'&&s[i+2]==')') cout<<i<<'\n',i+=2;
				break;
		}
}
