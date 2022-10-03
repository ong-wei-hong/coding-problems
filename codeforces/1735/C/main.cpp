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
string s;

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
		cin>>n>>s;
		vi ufds(26),rank(26,1);
		forn(i,26) ufds[i]=i;
		vi map(26,-1), r_map(26,-1);
		int num_taken=0;
		for(auto c: s)
			if(map[c-'a']!=-1) cout<<(char)(map[c-'a']+'a');
			else if(num_taken==24){
				vi remaining;
				forn(i,26) if(r_map[i]==-1) remaining.pb(i);
				map[c-'a']=remaining[0];
				int last_char;
				forn(i,26) if(map[i]==-1) last_char=i,map[i]=remaining[1];
				if(ufds_find_set(ufds,c-'a')==ufds_find_set(ufds,map[c-'a'])) swap(map[last_char],map[c-'a']);
				cout<<(char)(map[c-'a']+'a');
				}else for(char curr='a';curr<='z';++curr)
					if(r_map[curr-'a']==-1&&ufds_find_set(ufds,curr-'a')!=ufds_find_set(ufds,c-'a')){
						map[c-'a']=curr-'a';
						r_map[curr-'a']=c-'a';
						ufds_union_set(ufds,rank,c-'a',curr-'a');
						++num_taken;
						cout<<curr;
						break;
					}
		cout<<'\n';
	}
}


