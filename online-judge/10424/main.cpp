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

string s,t;

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
	while(getline(cin,s)) {
		getline(cin,t);
		int a=0;
		for(char c: s) {
			int i=toupper(c)-'A';
			if(0<=i&&i<=26) a+=i+1;
		}
		while(a>=10) {
			int i=a;
			a=0;
			for(;i;i/=10) a+=i%10;
		}
		int b=0;
		for(char c: t) {
			int i=toupper(c)-'A';
			if(0<=i&&i<=26) b+=i+1;
		}
		while(b>=10) {
			int i=b;
			b=0;
			for(;i;i/=10) b+=i%10;
		}
		cout<<fixed<<setprecision(2)<<min(100.0*a/b,100.0*b/a)<<" %\n";
	}
}
