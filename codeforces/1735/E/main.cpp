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
vi d1,d2;

bool solve(int dist){
	multiset<int, greater<int>> s1,s2;
	for(auto i: d1) s1.insert(i);
	for(auto i: d2) s2.insert(i);
	vi ans;

	while(max(*s1.begin(),*s2.begin())>dist){
		bool choose_s1 = (*s1.begin()) > (*s2.begin());
		auto& s_far = choose_s1 ? s1 : s2;
		auto& s_near = choose_s1 ? s2 : s1;

		if(!s_near.count((*s_far.begin())-dist)) return false;
	
		if(choose_s1) ans.pb(*s_far.begin());
		else ans.pb(dist - *s_far.begin());	
		
		s_near.erase(s_near.find(*s_far.begin()-dist));
		s_far.erase(s_far.begin());
	}

	auto p1 = s1.begin();
	auto p2 = s2.rbegin();
	for(;p1!=s1.end();++p1,++p2) if((*p1)+(*p2)!=dist) return false;

	for(auto i=s1.begin();i!=s1.end();++i) ans.pb(*i);
	sort(all(ans));
	int v=max(0,-ans[0]);
	cout<<"YES\n";
	for(auto i: ans) cout<<i+v<<' ';
	cout<<'\n'<<v<<' '<<dist+v<<'\n';
	return true;
}

void solve() {
	for(auto i: d2) if(solve(d1[0]+i)||solve(abs(d1[0]-i))) {
		return;
	}
	cout<<"NO\n";
}

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
	while(t--) {
		cin>>n;
		d1.resize(n);
		d2.resize(n);
		for(auto& i: d1) cin>>i;
		for(auto& i: d2) cin>>i;
		solve();
	}
}
