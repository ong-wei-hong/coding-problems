#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> findAnagrams(string s,string p) {
			if(p.size()>s.size()) return {};
			vector<int> pFreq(26,0);
			for(auto c: p) ++pFreq[c-'a'];
			int r=0;
			vector<int> sFreq(26,0);
			while(r<p.size()-1) ++sFreq[s[r++]-'a'];
			vector<int> ans;
			for(;r<s.size();++r) {
				++sFreq[s[r]-'a'];
				if(pFreq==sFreq) ans.push_back(r-p.size()+1);
				--sFreq[s[r-p.size()+1]-'a'];
			}
			return ans;
		}
	// time: O(s.size()+p.size()) = O(s.size())
};

