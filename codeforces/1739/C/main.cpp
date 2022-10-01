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

int t,n;
ll dp[61][3],choose[61][61],mod=998244353;

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
	for(int i=1;i<=60;++i) choose[i][1]=i,choose[i][i]=1;
	for(int i=2;i<=60;++i)
		for(int j=2;j<=60;++j)
			if(j<i) choose[i][j]=(choose[i-1][j-1]+choose[i-1][j])%mod;

	dp[2][0]=1;
	dp[2][1]=0;
	dp[2][2]=1;
	for(int i=4;i<=60;i+=2)
		dp[i][0]=(choose[i-1][i/2]+dp[i-2][1])%mod,dp[i][1]=(choose[i-2][i/2]+dp[i-2][0])%mod,dp[i][2]=1;

	cin>>t;
	while(t--){
		cin>>n;
		cout<<dp[n][0]<<' '<<dp[n][1]<<' '<<dp[n][2]<<'\n';
	}
}



