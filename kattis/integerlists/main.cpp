#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int t,n;
string p;

void solve() {
	cin>>p>>n;
	int x;
	char c;
	deque<int> q;
	forn(i,n) cin>>c>>x,q.push_back(x);
	cin>>c;
	if(n==0) cin>>c;
	bool r=0;
	for(auto c: p)
		switch(c) {
			case 'R': r=!r; break;
			case 'D':
				  if(q.empty()) {
					  cout<<"error\n";
					  return;
				  }
				  if(r) q.pop_back();
				  else q.pop_front();
		}
	if(q.empty()) {
		cout<<"[]\n";
		return;
	}
	cout<<'[';
	if(r){
		cout<<q.back();
		q.pop_back();
		for(auto it=q.rbegin();it!=q.rend();++it)cout<<','<<(*it);
		cout<<"]\n";
		return;
	}
	cout<<q.front();
	q.pop_front();
	for(auto it=q.begin();it!=q.end();++it) cout<<','<<(*it);
	cout<<"]\n";
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--) solve();
}
