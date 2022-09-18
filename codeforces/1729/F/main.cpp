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

int t,n,w,m,l,r,k;
string s;

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
		cin>>s>>w>>m;
		vector<vi> v(10);
		vi ps(s.size()+1,0);
		forn(i,s.size()) {
			ps[i+1]=ps[i]+s[i]-'0';
			if(i>=w-1) v[(ps[i+1]-ps[i-w+1])%9].pb(i-w+2);
		}
		while(m--) {
			cin>>l>>r>>k;
			int j=(ps[r]-ps[l-1])%9,l1=-1,l2=-1;
			forn(i,9) {
				int a=(k-((i*j)%9)+9)%9;
				if(i==a&&v[i].size()>=2&&(l1==-1||v[i][0]<l1)) l1=v[i][0],l2=v[i][1];
				else if(i!=a&&(!v[i].empty())&&(!v[a].empty())&&(l1==-1||v[i][0]<l1)) l1=v[i][0],l2=v[a][0];
			}
			cout<<l1<<' '<<l2<<'\n';
		}
	}
}

