#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vii vector<pair<int, int>>
#define pq priority_queue

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair

int t,n,m,sx,sy,d;

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

void cin_ignore() {
	cin.ignore(256,'\n');
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>m>>sx>>sy>>d;
		bool u=(sx-d)<=1,b=(sx+d)>=n,l=(sy-d)<=1,r=(sy+d)>=m;
		int w=0+u+b+l+r;
		if(w<2||(w==2&&((l&&b)||(r&&u)))) cout<<n+m-2;
		else cout<<-1;
		cout<<'\n';
	}
}
