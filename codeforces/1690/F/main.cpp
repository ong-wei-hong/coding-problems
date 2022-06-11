#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)

int t, n, p[5000];
ll ans;
bool b[5000];
char c[5000];
string s;

int main() {
	cin>>t;
	while(t--) {
		cin>>n>>s;
		ans=1L;
		forn(i,n) {
			b[i]=0;
			cin>>p[i];
			--p[i];
		}
		int i{0};
		while (i<n) {
			int k{0};
			while (!b[i]) {
				c[k++]=s[i];
				b[i]=1;
				i=p[i];
			}
			++i;
			if (k==0) continue;
			for(int l{1};l<k+1;++l) {
				bool v{1};
				forn(m,k)
					if (c[m]!=c[(m+l)%k]) {
						v=0;
						break;
					}
				if (v) {
					ans=lcm(ans,l);
					break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
