#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()

int n, a[20];
string s;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>n;
	while(n){
		forn(i,n) cin>>a[i],--a[i];
		cin.ignore(256,'\n');
		getline(cin,s);
		cout<<'\'';
		for(int i=0;i<s.size();i+=n)
			forn(j,n) {
				int k{i+a[j]};
				if(k>=s.size()) cout<<' ';
				else cout<<s[k];
			}
		cout<<"'\n";
		cin>>n;
	}
	return 0;
}
