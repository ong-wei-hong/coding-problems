#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

#define fi first
#define se second
#define pb push_back
#define mp make_pair

int n,a,b;

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n) {
		vector<bool> v(n);
		cin>>a;
		forn(i,n-1) {
			cin>>b;
			int c=abs(b-a);
			if(c>0&&c<n) v[c]=1;
			a=b;
		}
		bool bo=1;
		forn(i,n-1) bo=bo&&v[i+1];
		if(bo) cout<<"Jolly\n";
		else cout<<"Not jolly\n";
	}
}
