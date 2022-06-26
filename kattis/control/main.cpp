#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int n,m,ufds[500001],s[500001];

void solve() {
}

int find(int i) {
	if(ufds[i]!=i) ufds[i]=find(ufds[i]);
	return ufds[i];
}

void union_set(int i,int j) {
	i=find(i),j=find(j);
	if(i==j) return;
	if(s[i]>s[j]) swap(i,j);
	ufds[i]=j;
	s[j]+=s[i];
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	//cin>>t;
	//while(t--) solve();
	forn(i,500002) ufds[i]=i,s[i]=1;
	cin>>n;
	int ans{0};
	while(n--) {
		cin>>m;
		vi v(m);
		unordered_set<int> r{};
		forn(i,m) cin>>v[i],r.insert(find(v[i]));
		int t=0;
		for(auto &i: r) t+=s[i];
		if(t==m) {
			++ans;
			for(auto &i: v) union_set(v[0],i);
		}
	}
	cout<<ans<<'\n';
}
