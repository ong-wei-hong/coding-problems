#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()

int t,n,a[300000],b[300000][3],v,u;

void depth(int i,int j){
	a[i]=1;
	forn(k,3) {
		if(b[i][k]==-1) return;
		if(b[i][k]!=j) depth(b[i][k],i), a[i]+=a[b[i][k]];
	}
}

int ans(int i,int j) {
	if(b[i][1]==-1) return 0;
	if(b[i][2]==-1)
		forn(k,2)
			if(b[i][k]!=j)
				return a[b[i][k]]-1;
	int m{b[i][0]},n{b[i][1]};
	if(m==j)m=b[i][2];
	if(n==j)n=b[i][2];
	return max(ans(m,i)+a[n]-1,ans(n,i)+a[m]-1);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		forn(i,n)b[i][0]=-1,b[i][1]=-1,b[i][2]=-1;
		b[0][0]=-2;
		forn(i,n-1){
			cin>>v>>u,--v,--u;
			if(b[v][1]!=-1) b[v][2]=b[v][1];
			if(b[v][0]!=-1) b[v][1]=b[v][0];
			b[v][0]=u;
			if(b[u][1]!=-1) b[u][2]=b[u][1];
			if(b[u][0]!=-1) b[u][1]=b[u][0];
			b[u][0]=v;
		}
		depth(0,-2);
		cout<<ans(0,-2)<<'\n';
	}
	return 0;
}

