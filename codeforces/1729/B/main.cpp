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

int q,n;
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
	cin>>q;
	while(q--) {
		cin>>n>>s;
		int l=s.size()-1;
		stack<char> st;
		while(l>=0) {
			if(s[l]=='0') {
				st.push((s[l-2]-'0')*10+s[l-1]-'0'+'a'-1);
				l-=3;
			} else st.push(s[l--]-'0'+'a'-1);
		}
		while(!st.empty()) cout<<st.top(),st.pop();
		cout<<'\n';
	}
}
