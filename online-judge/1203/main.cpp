#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

priority_queue<pair<int,ii>,vector<pair<int,ii>>,greater<pair<int,ii>>> pq;
string s;
int t,p,f;

void solve() {
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    //cin>>t;
    //while(t--) solve();
    cin>>s;
    while(s!="#") {
	    cin>>p>>f;
	    pq.push(pair<int,ii>(f,ii(p,f)));
	    cin>>s;
    }
    cin>>t;
    while(t--) {
	    auto i=pq.top();
	    pq.pop();
	    cout<<i.second.first<<'\n';
	    i.first+=i.second.second;
	    pq.push(i);
    }
}
