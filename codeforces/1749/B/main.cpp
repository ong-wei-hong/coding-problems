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
 
int t,n,a,b;
 
void solve();
 
void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}
 
void cin_ignore() {
	cin.ignore(256,'\n');
}
 
int ufds_find_set(vi& ufds, int i){
	if(ufds[i]==i) return i;
	return ufds[i]=ufds_find_set(ufds,ufds[i]);
}
 
void ufds_union_set(vi& ufds, vi& rank, int i, int j){
	i = ufds_find_set(ufds,i);
	j = ufds_find_set(ufds,j);
	if(i==j) return;
	if(rank[i]>rank[j]) ufds[j]=i;
	else ufds[i]=j,++rank[j];
}
 
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ll ans=0;
		forn(i,n) cin>>a,ans+=a;
		int maxi=0;
		forn(i,n) cin>>b, maxi=max(maxi,b),ans+=b;
		cout<<ans-maxi<<'\n';
	}
}
