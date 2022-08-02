#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<string> letterCombination(string digits) {
			if(digits.size()==0) return {};
			const string map[] {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
			queue<string> q;
			q.push("");
			for(auto c: digits) {
				int l=q.size();
				while(l--) {
					string curr=q.front();
					q.pop();
					for(auto ch: map[c-'2']) q.push(curr+ch);
				}
			}
			vector<string> result;
			while(!q.empty()) result.push_back(q.front()),q.pop();
			return result;
		}
	// time: O(n * 4 ** n) where n=digits.size()
	// space: O(n * 4 ** n) where n=digits.size()
};
