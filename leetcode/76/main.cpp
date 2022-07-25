#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string minWindow(string s,string t) {
			unordered_map<char,int> t_map;
			for(auto c: t) {
				if(t_map.find(c)==t_map.end()) t_map[c]=0;
				++t_map[c];
			}
		
			// split into 2 phases
			// first find the min index n where 0 to n contains all chars in t
			// then maintain the substring
			
			int num_unique=t_map.size(),end=0;
			unordered_map<char,int> s_map;

			while(end<s.length()) {
				char c = s[end];
				if(s_map.find(c) == s_map.end()) s_map[c]=0;
				++s_map[c];

				auto it = t_map.find(c);
				num_unique -= it!=t_map.end() && it->second==s_map[c];
				if(num_unique==0) break;

				++end;
			}

			if(num_unique==0) return "";

			int start=0,ans_start=0,ans_end=end;
			while(end<s.length()) {
				while(1) {
					char c = s[start];
					auto it = t_map.find(c);
					if(it != t_map.end() && it->second==s_map[c]) break;

					++start;
					--s_map[c];
				}

				if((end-start)<(ans_end-ans_start)) ans_start=start,ans_end=end;

				while(end<s.length()) {
					char c = s[end];
					if(s_map.find(c)==s_map.end()) s_map[c]=0;
					++s_map[c];

					if(c==s[start]) break;

					++end;
				}
			}
			return s.substr(ans_start,ans_end-ans_start+1);
		}
	// time: O(s.length() + t.length())
};
