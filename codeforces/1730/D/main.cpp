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

int t,n;
string s1,s2;

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
	while(t--){
		cin>>n>>s1>>s2;
		map<ii,int> m;
		forn(i,s1.size()){
			ii p=mp(s1[i],s2[n-i-1]);
			if(p.fi>p.se) swap(p.fi,p.se);
			++m[p];
		}
		bool valid=1,mid=0;
		for(auto& p: m)
			if(p.se%2)
				if(p.fi.fi!=p.fi.se||mid) {
					valid=0;
					break;
				} else mid=1;
		if(valid) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
