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

int t;
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
		cin>>s;
		vii v;
		int f=s[0],l=s[s.size()-1];
		for(int i=1;i<s.size()-1;++i) if(s[i]==f||s[i]==l||(s[i]<f!=s[i]<l))
			v.pb(mp(s[i],i));
		sort(all(v));
		cout<<abs(l-f)<<' '<<v.size()+2<<"\n1 ";
		if(f<l)
			for(auto& p: v) cout<<p.se+1<<' ';
		else 
			for(auto it=v.rbegin();it<v.rend();++it) cout<<(it->se)+1<<' ';
		cout<<s.size()<<'\n';
	}
}
