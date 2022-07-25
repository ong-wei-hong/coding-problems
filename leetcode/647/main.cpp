#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int countSubstrings(string s) {
			int ans=0;
			// first count odd length palindromes, then even length ones
			for(int i=0;i<s.length();++i) {
				int start=i,end=i;
				while(start>=0&&end<s.length()&&s[start]==s[end]) --start,++end,++ans;
			}
			for(int i=0;i<s.length()-1;++i) {
				int start=i,end=i+1;
				while(start>=0&&end<s.length()&&s[start]==s[end]) --start,++end,++ans;
			}
			return ans;
		}
	// time: O(s.length()**2)
};
