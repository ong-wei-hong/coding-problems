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

int t,d;
string m;

void solve() {
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>t;
	while(t--) {
		cin>>d>>m;
		if(m=="Mar")
			if(d<=20) cout<<"Pisces\n";
			else cout<<"Aries\n";
		else if(m=="Apr")
			if(d<=20) cout<<"Aries\n";
			else cout<<"Taurus\n";
		else if(m=="May")
			if(d<=20) cout<<"Taurus\n";
			else cout<<"Gemini\n";
		else if(m=="Jun")
			if(d<=21) cout<<"Gemini\n";
			else cout<<"Cancer\n";
		else if(m=="Jul")
			if(d<=22) cout<<"Cancer\n";
			else cout<<"Leo\n";
		else if(m=="Aug")
			if(d<=22) cout<<"Leo\n";
			else cout<<"Virgo\n";
		else if(m=="Sep")
			if(d<=21) cout<<"Virgo\n";
			else cout<<"Libra\n";
		else if(m=="Oct")
			if(d<=22) cout<<"Libra\n";
			else cout<<"Scorpio\n";
		else if(m=="Nov")
			if(d<=22) cout<<"Scorpio\n";
			else cout<<"Sagittarius\n";
		else if(m=="Dec")
			if(d<=21) cout<<"Sagittarius\n";
			else cout<<"Capricorn\n";
		else if(m=="Jan")
			if(d<=20) cout<<"Capricorn\n";
			else cout<<"Aquarius\n";
		else if(m=="Feb")
			if(d<=19) cout<<"Aquarius\n";
			else cout<<"Pisces\n";
	}
}
