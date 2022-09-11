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
		cin>>n;
		vi a(n), b(n);
		for(auto& i: a) cin>>i;
		for(auto& i: b) cin>>i;
		pq<int> qa(all(a));
		pq<int> qb(all(b));
		int ans=0;
		while(!qa.empty()) {
			if(qa.top()==qb.top()) {
				qa.pop(),qb.pop();
				continue;
			}
			++ans;
			if(qa.top()>qb.top()) {
				qa.push(to_string(qa.top()).size());
				qa.pop();
			} else {
				qb.push(to_string(qb.top()).size());
				qb.pop();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
