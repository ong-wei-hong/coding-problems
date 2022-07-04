#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>

#define forn(i, n) for(int i=0; i<int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a,rend()

#define fi first
#define se second
#define pb push_back

int n;
string s;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
    cin>>n;
    forn(i,n) {
        cin>>s;
        if(s=="1"||s=="4"||s=="78") cout<<"+\n";
        else if(s.length()>=2&&s.substr(s.length()-2)=="35") cout<<"-\n";
        else if(s.length()>=2&&s[0]=='9'&&s[s.length()-1]=='4') cout<<"*\n";
        else if(s.length()>=3&&s.substr(0,3)=="190") cout<<"?\n";
    }
}

