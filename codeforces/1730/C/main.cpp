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
	while(t--){
		cin>>s;
		vi v(s.size()),mini(s.size()),cnt(10);
		forn(i,s.size()) v[i]=s[i]-'0';
		mini[s.size()-1]=v[s.size()-1];
		for(int i=s.size()-2;i>=0;--i) mini[i]=min(mini[i+1],v[i]);
		int i=0;
		while(i<s.size()){
			int mini_index=-1;
			for(int j=i;j<s.size();++j) if(v[j]==mini[i]) mini_index=j;
			if(mini_index==-1) break;
			for(int j=i;j<=mini_index;++j) 
				if(v[j]==mini[i]) ++cnt[v[j]];
				else ++cnt[min(v[j]+1,9)];
			i=mini_index+1;
		}
		forn(j,10)
			forn(k,cnt[j]) cout<<j;
		cout<<'\n';
	}
}

		


