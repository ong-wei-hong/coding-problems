#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			unordered_map<char,int> freq;
			int start=0,end=0,longest=0;
			while(end<s.size()) {
				char c = s[end];
				if(freq.find(c) == freq.end()) freq[c]=0;
				++freq[c];

				while(freq[c]>1) --freq[s[start++]];

				longest = max(longest, end-start+1);
				++end;
			}
			return longest;
		}
	// time: O(s.length())
};
