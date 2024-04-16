#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> ops;
vi v;

void op(int start, int end) {
	if(start==end) {
		if(v[start]!=0) v[start]=0,ops.push_back({start,start});
		return;
	}

	op(start,end-1);
	if(v[end]!=end-start) {
		rep(i,start,end+1) v[i]=end-start;
		ops.push_back({start,end}),op(start,end-1);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin>>n;

	v.resize(n);
	for(auto &i: v) cin>>i;

	int ans=0,best=0;
	rep(mask,0,(1<<n)) {
		int curr=0;
		for(int i=0,j=0;i<n;) {
			if((mask>>i)&1) {
				j=i;
				while(j<n&&((mask>>j)&1)) ++j;
				curr+=(j-i)*(j-i);
				i=j;
			} else curr+=v[i],++i;
		}
		if(curr>best) best=curr,ans=mask;
	}

	for(int i=0,j;i<n;++i) 
		if((ans>>i)&1) {
			j=i;
			while(j<n&&((ans>>j)&1)) ++j;
			--j;
			op(i,j);
			ops.push_back({i,j});
			i=j;
		}

	cout<<best<<' '<<ops.size()<<'\n';
	for(auto &p: ops) cout<<p.first+1<<' '<<p.second+1<<'\n';

}
