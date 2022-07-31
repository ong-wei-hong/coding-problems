#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			unordered_map<string,vector<string>> m;
			for(auto& s: strs) {
				string t=s;
				sort(t.begin(),t.end());
				m[t].push_back(s);
			}
			vector<vector<string>> result;
			for(auto& it: m) result.push_back(it.second);
			return result;
		}
	// time: O(n * m log m) where n=strs.size() and m=strs[i].length()
};
