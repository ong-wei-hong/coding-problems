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

int n;
char op;
ll r,a,b;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>n;
	r=1;
	while(n--) {
		cin>>a>>op>>b;
		switch(op) {
			case '+':
				r=a+b-r;
				break;
			case '-':
				r*=a-b;
				break;
			case '*':
				r=a*b*a*b;
				break;
			case '/':
				if(a&1) r=(a+1)/2;
				else r=a/2;
				break;
		}
		cout<<r<<'\n';
	}
}
