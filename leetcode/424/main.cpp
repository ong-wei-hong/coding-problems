#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int characterReplacement(string s,int k) {
			vector<int> freq(26,0);
			int ans=0,left=0,right=0,maxRepeated=0;
			for(auto c: s) {
				++right;
				maxRepeated=max(maxRepeated,++freq[c-'A']);
				while(right-left-maxRepeated>k) {
					--freq[s[left]-'A'];
					++left;
				}
				ans=max(ans,right-left);
			}
			return ans;
		}
	// time: O(s.size())
};
