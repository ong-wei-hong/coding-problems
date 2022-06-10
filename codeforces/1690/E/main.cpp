#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)

int t, n, k, a[200001];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin>>t;
	while(t--) {
		cin>>n>>k;
		ll ans{0};
		forn(i,n) {
			cin>>a[i];
			ans+=a[i]/k;
			a[i]%=k;
		}
		sort(a,a+n);
		int i{0},j{n-1};
		while(i<j)
			if(a[i]+a[j]>=k) ++i,--j,++ans;
			else ++i;
		cout<<ans<<'\n';
	}
	return 0;
}
