#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m;
ii p[500];

int ask(const string& s) {
	cout << "? " << s << endl;
	int r;
	cin >> r;
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	string s(m, '0');
	for(int i=0; i<m; ++i) {
		s[i] = '1';
		int r = ask(s);
		s[i] = '0';
		p[i] = ii(r, i);
	}
	sort(p, p+m);
	int a=0;
	for(int i=0; i<m; ++i) {
		s[p[i].second] = '1';
		int r = ask(s);
		if((r-a)==p[i].first) a += p[i].first;
		else s[p[i].second] = '0';
	}
	cout << "! "<<a<<endl;
}
