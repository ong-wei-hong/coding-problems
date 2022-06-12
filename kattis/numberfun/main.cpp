#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)

int n,a,b,c;

int main() {
	cin>>n;
	while(n--) {
		cin>>a>>b>>c;
		if((a+b==c)||(a*b==c)||(a-b==c)||(b-a==c)||((a%b==0)&&(a/b==c))||((b%a==0)&&(b/a==c)))
			cout<<"Possible";
		else cout<<"Impossible";
		cout<<'\n';
	}
	return 0;
}
