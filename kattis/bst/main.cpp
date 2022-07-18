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

int n,a[300001],x;
set<int> se;
ll c;

void solve();

void file() {
	freopen("","r",stdin);
	freopen("","w",stdout);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    while(n--) {
        cin>>x;
        se.insert(x);
        auto it1=se.find(x),it2=se.find(x);
        int h=-1;
        if(it1!=se.begin()) --it1,h=a[*it1];
        if(it2!=se.end()) {
            ++it2;
            if(it2!=se.end()) h=max(h,a[*it2]);
        }
        ++h;
        c+=h;
        a[x]=h;
        cout<<c<<'\n';
    }
}



