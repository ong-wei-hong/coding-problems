#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)

int t,n,m,a[100000],k,d;
set<int> s;

int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>t;
	while(t--) {
		s.clear();
		cin>>n>>m;
		forn(i,n) {
			cin>>a[i];
			if(s.empty()||a[i]<a[*s.rbegin()]) s.insert(i);
		}
		while(m--) {
			cin>>k>>d;
			a[--k]-=d;
			auto it=s.upper_bound(k);
			if(it!=s.begin()&&a[*prev(it)]>a[k]) s.insert(k);
			while(1) {
				it=s.upper_bound(k);
				if(it!=s.end()&&a[*it]>=a[k]) s.erase(it);
				else break;
			}
			cout<<s.size()<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
		
				
