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

int comp(char c,char d) {
	return c>d?-1:(c>d?1:0);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>s;
		int n=s.size();
		vector<vi> dp(n+1,vi(n+1,0));
		for(int len=2;len<=n;len+=2) forn(l,n-len+1) {
			int r=l+len;
			dp[l][r]=1;
			int res=-1;
			if(dp[l+1][r-1]!=0) res=max(res,dp[l+1][r-1]);
			else res=max(res,comp(s[l],s[r-1]));
			if(dp[l+2][r]!=0) res=max(res,dp[l+2][r]);
			else res=max(res,comp(s[l],s[l+1]));
			dp[l][r]=min(dp[l][r],res);
			res=-1;
			if(dp[l+1][r-1]!=0) res=max(res,dp[l+1][r-1]);
			else res=max(res,comp(s[r-1],s[l]));
			if(dp[l][r-2]!=0) res=max(res,dp[l][r-2]);
			else res=max(res,comp(s[r-1],s[r-2]));
			dp[l][r]=min(dp[l][r],res);
		}
		if(dp[0][n]==-1) cout<<"Alice\n";
		else if(dp[0][n]==0) cout<<"Draw\n";
		else cout<<"Bob\n";
	}
}
