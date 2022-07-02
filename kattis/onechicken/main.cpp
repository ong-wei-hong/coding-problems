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

int n,m;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>n>>m;
	if(n>m) {
		if(n==(m+1)) {
			cout<<"Dr. Chaz needs 1 more piece of chicken!\n";
			return 0;
		}
		cout<<"Dr. Chaz needs "<<n-m<<" more pieces of chicken!\n";
		return 0;
	}
	if(m==(n+1)) {
		cout<<"Dr. Chaz will have 1 piece of chicken left over!\n";
		return 0;
	}
	cout<<"Dr. Chaz will have "<<m-n<<" pieces of chicken left over!\n";
}
