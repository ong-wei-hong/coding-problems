#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string longestPalindrome(string s) {
			int ansL=-1,ans=0;
			for(int i=0;i<s.length();++i) {
				int l=i,r=i;
				while(l>=0&&r<s.length()&&s[l]==s[r]) --l,++r;
				if(r-l-1>ans) ans=r-l-1,ansL=l+1;
				l=i,r=i+1;
				while(l>=0&&r<s.length()&&s[l]==s[r]) --l,++r;
				if(r-l-1>ans) ans=r-l-1,ansL=l+1;
			}
			return s.substr(ansL,ans);
		}
	// time: O(n**2) where n=s.length()
};
