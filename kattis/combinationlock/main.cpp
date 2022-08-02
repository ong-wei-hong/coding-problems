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

int a,b,c,d;

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
	while(cin>>a>>b>>c>>d) {
		if(!a&&!b&&!c&&!d) break;
		int ans=720;
		ans+=((40+a-b)*9)%360;
		ans+=360;
		ans+=((40-b+c)*9)%360;
		ans+=((40+c-d)*9)%360;
		cout<<ans<<'\n';
	}
}
