#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

int t,n,s;
ll a[200001];

void solve() {
	cin>>n>>s;
	int ans{INT_MAX};
	forn(i,n) cin>>a[i+1],a[i+1]+=a[i];
	for(int i=1;i<=n;++i) {
		int l{i},r{n},pos{-1};
		while(l<=r) {
			int mid {(l+r)>>1};
			if(a[mid]-a[i-1]<=s) {
				pos=mid;
				l=mid+1;
			} else r=mid-1;
		}
		if(pos==-1||a[pos]-a[i-1]!=s) continue;
		ans=min(ans,n-pos+i-1);
	}
	cout<<(ans==INT_MAX?-1:ans)<<'\n';

}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--) solve();
}
