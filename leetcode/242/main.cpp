#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool isAnagram(string s,string t) {
			if(s.size()!=t.size()) return false;

			int sa[26],ta[26];
			for(int i=0;i<26;++i) sa[i]=ta[i]=0;
			for(auto c: s) ++sa[c-'a'];
			for(auto c: t) ++ta[c-'a'];
			for(int i=0;i<26;++i) if(sa[i]!=ta[i]) return false;
			return true;
		}
	// time: O(s.size()+t.size())
};
