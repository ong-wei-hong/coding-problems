#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)

int t,n,result;

int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		result=1;
		forn(i,n)
			result=(result*(i+1))%10;
		cout<<result<<'\n';
	}
	return 0;
}
